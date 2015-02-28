/* -----------------------------------------------------------------------
 *
 * $Id$
 *
 * Copyright 2010, Kim, Tae-Sung. All rights reserved.
 * See copyright.txt for details
 *
 * -------------------------------------------------------------------- */

#include "imagecodec.h"
#include "ijg_codec.h"
#include <stdio.h>
#include <stdlib.h>

//--------

extern "C" {
	#include "8/jpeglib.h"
}

#include <setjmp.h>
#include <memory.h>

namespace dicom { //------------------------------------------------------

typedef struct {
	int len;
	unsigned char *buf;
	unsigned char *ptr;
} MEMFILE;

// codes for managing error
struct my_error_mgr {
  struct jpeg_error_mgr pub;	/* "public" fields */
  jmp_buf setjmp_buffer;	/* for return to caller */
};

typedef struct my_error_mgr * my_error_ptr;
static void my_error_exit (j_common_ptr cinfo)
{
  my_error_ptr myerr = (my_error_ptr) cinfo->err;
  (*cinfo->err->output_message) (cinfo);
  longjmp(myerr->setjmp_buffer, 1);
}

int encode_ijg_jpeg8
	(char *src, int srcstep, char **_dst, int *_dstlen,
		PIXELDATA_INFO *pi, JPEG_MODE jmode, int quality )
{
	struct jpeg_compress_struct cinfo;

	// Step 1: allocate and initialize JPEG compression object
	struct jpeg_error_mgr jerr;
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);


	// Step 2: specify data destination

	MEMFILE mem;
	mem.len = srcstep*pi->rows*2; // just reserve a large enough buffer
	mem.buf = (unsigned char*)malloc(mem.len);
	mem.ptr = mem.buf;
	jpeg_stdio_dest(&cinfo, (FILE *)&mem);

	// Step 3: set parameters for compression

	cinfo.image_width = pi->cols;
	cinfo.image_height = pi->rows;
	cinfo.input_components = pi->ncomps;
	cinfo.in_color_space = (pi->ncomps==3?JCS_RGB:JCS_GRAYSCALE);

	jpeg_set_defaults(&cinfo);
	switch (jmode) {
	case JPEG_BASELINE:
		jpeg_set_quality(&cinfo, quality, TRUE /* force baseline */);
		break;
	case JPEG_EXTENDED:
		jpeg_set_quality(&cinfo, quality, FALSE);
		break;
	case JPEG_LOSSLESS:
	case JPEG_LOSSLESS_SV1:
		jpeg_simple_lossless(&cinfo, 1 /* predictor */, 0 /* pt */);
		break;
	}

	// Step 4: Start compressor

	jpeg_start_compress(&cinfo, TRUE);

	// Step 5: while (scan lines remain to be written)
	//           jpeg_write_scanlines(...);

	JSAMPROW row_pointer[1];
	if (srcstep < 0) src += -srcstep*(pi->rows-1);
	while (cinfo.next_scanline < cinfo.image_height) {
		//row_pointer[0] = (JSAMPROW)& src[cinfo.next_scanline * srcstep];
		row_pointer[0] = (JSAMPROW)src;
		(void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
		src += srcstep;
	}

	// Step 6: Finish compression

	jpeg_finish_compress(&cinfo);

	// Step 7: release JPEG compression object

	jpeg_destroy_compress(&cinfo);

	*_dst = (char *)mem.buf;
	*_dstlen = int(mem.ptr-mem.buf);

	return DICOM_OK;
}

int decode_ijg_jpeg8
	(char *src, int srclen,char *dst, int dststep, PIXELDATA_INFO *pi)
{
	struct jpeg_decompress_struct cinfo;

	// Step 1: allocate and initialize JPEG decompression object
	struct my_error_mgr jerr;
	cinfo.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = my_error_exit;
	if (setjmp(jerr.setjmp_buffer)) {
	    jpeg_destroy_decompress(&cinfo);
	    return DICOM_ERROR;
	}
	jpeg_create_decompress(&cinfo);

	// Step 2: specify data source

	// init source stream
	MEMFILE mem;
	mem.len = srclen;
	mem.buf = (unsigned char*)src;
	mem.ptr = mem.buf;
	jpeg_stdio_src(&cinfo, (FILE *)&mem);

	// Step 3: read file parameters with jpeg_read_header()
	(void) jpeg_read_header(&cinfo, TRUE);

	pi->cols 	= cinfo.image_width;
	pi->rows	= cinfo.image_height;
	pi->ncomps	= cinfo.num_components;
	pi->prec	= cinfo.data_precision;
	//_imginf->mode // read_jpeg_header() filled this value

	// Step 4: set parameters for decompression

	/* In this example, we don't need to change any of the defaults set by
	 * jpeg_read_header(), so we do nothing here.
	 */

	// Step 5: Start decompressor

	(void) jpeg_start_decompress(&cinfo);
	int row_stride = cinfo.output_width * cinfo.output_components;
	JSAMPARRAY buffer = (*cinfo.mem->alloc_sarray)
			((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

	// Step 6: while (scan lines remain to be read)
	//             jpeg_read_scanlines(...);

	if (dststep < 0) dst += -dststep*(pi->rows-1);

	while (cinfo.output_scanline < cinfo.output_height) {
		(void) jpeg_read_scanlines(&cinfo, buffer, 1);
		memcpy(dst, buffer[0], row_stride); // bpp = 1
		dst += dststep;
	}

	// Step 7: Finish decompression
	(void) jpeg_finish_decompress(&cinfo);

	// Step 8: Release JPEG decompression object
	jpeg_destroy_decompress(&cinfo);

	return DICOM_OK;
}

} // namespace dicom ------------------------------------------------------
