/* jconfig.cfg --- source file edited by configure script */
/* see jconfig.doc for explanations */

#define HAVE_PROTOTYPES
#define HAVE_UNSIGNED_CHAR
#define HAVE_UNSIGNED_SHORT
/* #undef void */
/* #undef const */
#undef CHAR_IS_UNSIGNED
#define HAVE_STDDEF_H
#define HAVE_STDLIB_H
#undef NEED_BSD_STRINGS
#undef NEED_SYS_TYPES_H
#undef NEED_FAR_POINTERS
#undef NEED_SHORT_EXTERNAL_NAMES
/* Define this if you get warnings about undefined structures. */
#undef INCOMPLETE_TYPES_BROKEN

#ifdef JPEG_INTERNALS

#undef RIGHT_SHIFT_IS_UNSIGNED
#undef INLINE
/* These are for configuring the JPEG memory manager. */
#undef DEFAULT_MAX_MEM
#undef NO_MKTEMP

#endif /* JPEG_INTERNALS */

#ifdef JPEG_CJPEG_DJPEG

#define BMP_SUPPORTED		/* BMP image file format */
#define GIF_SUPPORTED		/* GIF image file format */
#define PPM_SUPPORTED		/* PBMPLUS PPM/PGM image file format */
#undef RLE_SUPPORTED		/* Utah RLE image file format */
#define TARGA_SUPPORTED		/* Targa image file format */

#undef TWO_FILE_COMMANDLINE
#undef NEED_SIGNAL_CATCHER
#undef DONT_USE_B_MODE

/* Define this if you want percent-done progress reports from cjpeg/djpeg. */
#undef PROGRESS_REPORT

#endif /* JPEG_CJPEG_DJPEG */

/* name mangling -------------------------------------------------------*/
#define jcopy_block_row _LIBIJG8_jcopy_block_row
#define jcopy_sample_rows _LIBIJG8_jcopy_sample_rows
#define jdiv_round_up _LIBIJG8_jdiv_round_up
#define jinit_1pass_quantizer _LIBIJG8_jinit_1pass_quantizer
#define jinit_2pass_quantizer _LIBIJG8_jinit_2pass_quantizer
#define jinit_arith_decoder _LIBIJG8_jinit_arith_decoder
#define jinit_arith_encoder _LIBIJG8_jinit_arith_encoder
#define jinit_c_codec _LIBIJG8_jinit_c_codec
#define jinit_c_coef_controller _LIBIJG8_jinit_c_coef_controller
#define jinit_c_diff_controller _LIBIJG8_jinit_c_diff_controller
#define jinit_c_main_controller _LIBIJG8_jinit_c_main_controller
#define jinit_c_master_control _LIBIJG8_jinit_c_master_control
#define jinit_c_prep_controller _LIBIJG8_jinit_c_prep_controller
#define jinit_c_scaler _LIBIJG8_jinit_c_scaler
#define jinit_color_converter _LIBIJG8_jinit_color_converter
#define jinit_color_deconverter _LIBIJG8_jinit_color_deconverter
#define jinit_compress_master _LIBIJG8_jinit_compress_master
#define jinit_d_codec _LIBIJG8_jinit_d_codec
#define jinit_d_coef_controller _LIBIJG8_jinit_d_coef_controller
#define jinit_d_diff_controller _LIBIJG8_jinit_d_diff_controller
#define jinit_d_main_controller _LIBIJG8_jinit_d_main_controller
#define jinit_d_post_controller _LIBIJG8_jinit_d_post_controller
#define jinit_d_scaler _LIBIJG8_jinit_d_scaler
#define jinit_differencer _LIBIJG8_jinit_differencer
#define jinit_downsampler _LIBIJG8_jinit_downsampler
#define jinit_forward_dct _LIBIJG8_jinit_forward_dct
#define jinit_input_controller _LIBIJG8_jinit_input_controller
#define jinit_inverse_dct _LIBIJG8_jinit_inverse_dct
#define jinit_lhuff_decoder _LIBIJG8_jinit_lhuff_decoder
#define jinit_lhuff_encoder _LIBIJG8_jinit_lhuff_encoder
#define jinit_lossless_c_codec _LIBIJG8_jinit_lossless_c_codec
#define jinit_lossless_d_codec _LIBIJG8_jinit_lossless_d_codec
#define jinit_lossy_c_codec _LIBIJG8_jinit_lossy_c_codec
#define jinit_lossy_d_codec _LIBIJG8_jinit_lossy_d_codec
#define jinit_marker_reader _LIBIJG8_jinit_marker_reader
#define jinit_marker_writer _LIBIJG8_jinit_marker_writer
#define jinit_master_decompress _LIBIJG8_jinit_master_decompress
#define jinit_memory_mgr _LIBIJG8_jinit_memory_mgr
#define jinit_merged_upsampler _LIBIJG8_jinit_merged_upsampler
#define jinit_phuff_decoder _LIBIJG8_jinit_phuff_decoder
#define jinit_phuff_encoder _LIBIJG8_jinit_phuff_encoder
#define jinit_shuff_decoder _LIBIJG8_jinit_shuff_decoder
#define jinit_shuff_encoder _LIBIJG8_jinit_shuff_encoder
#define jinit_undifferencer _LIBIJG8_jinit_undifferencer
#define jinit_upsampler _LIBIJG8_jinit_upsampler
#define jpeg_CreateCompress _LIBIJG8_jpeg_CreateCompress
#define jpeg_CreateDecompress _LIBIJG8_jpeg_CreateDecompress
#define jpeg_abort _LIBIJG8_jpeg_abort
#define jpeg_abort_compress _LIBIJG8_jpeg_abort_compress
#define jpeg_abort_decompress _LIBIJG8_jpeg_abort_decompress
#define jpeg_add_quant_table _LIBIJG8_jpeg_add_quant_table
#define jpeg_alloc_huff_table _LIBIJG8_jpeg_alloc_huff_table
#define jpeg_alloc_quant_table _LIBIJG8_jpeg_alloc_quant_table
#define jpeg_calc_output_dimensions _LIBIJG8_jpeg_calc_output_dimensions
#define jpeg_consume_input _LIBIJG8_jpeg_consume_input
#define jpeg_copy_critical_parameters _LIBIJG8_jpeg_copy_critical_parameters
#define jpeg_default_colorspace _LIBIJG8_jpeg_default_colorspace
#define jpeg_destroy _LIBIJG8_jpeg_destroy
#define jpeg_destroy_compress _LIBIJG8_jpeg_destroy_compress
#define jpeg_destroy_decompress _LIBIJG8_jpeg_destroy_decompress
#define jpeg_fdct_float _LIBIJG8_jpeg_fdct_float
#define jpeg_fdct_ifast _LIBIJG8_jpeg_fdct_ifast
#define jpeg_fdct_islow _LIBIJG8_jpeg_fdct_islow
#define jpeg_fill_bit_buffer _LIBIJG8_jpeg_fill_bit_buffer
#define jpeg_finish_compress _LIBIJG8_jpeg_finish_compress
#define jpeg_finish_decompress _LIBIJG8_jpeg_finish_decompress
#define jpeg_finish_output _LIBIJG8_jpeg_finish_output
#define jpeg_free_large _LIBIJG8_jpeg_free_large
#define jpeg_free_small _LIBIJG8_jpeg_free_small
#define jpeg_gen_optimal_table _LIBIJG8_jpeg_gen_optimal_table
#define jpeg_get_large _LIBIJG8_jpeg_get_large
#define jpeg_get_small _LIBIJG8_jpeg_get_small
#define jpeg_has_multiple_scans _LIBIJG8_jpeg_has_multiple_scans
#define jpeg_huff_decode _LIBIJG8_jpeg_huff_decode
#define jpeg_idct_1x1 _LIBIJG8_jpeg_idct_1x1
#define jpeg_idct_2x2 _LIBIJG8_jpeg_idct_2x2
#define jpeg_idct_4x4 _LIBIJG8_jpeg_idct_4x4
#define jpeg_idct_float _LIBIJG8_jpeg_idct_float
#define jpeg_idct_ifast _LIBIJG8_jpeg_idct_ifast
#define jpeg_idct_islow _LIBIJG8_jpeg_idct_islow
#define jpeg_input_complete _LIBIJG8_jpeg_input_complete
#define jpeg_make_c_derived_tbl _LIBIJG8_jpeg_make_c_derived_tbl
#define jpeg_make_d_derived_tbl _LIBIJG8_jpeg_make_d_derived_tbl
#define jpeg_mem_available _LIBIJG8_jpeg_mem_available
#define jpeg_mem_init _LIBIJG8_jpeg_mem_init
#define jpeg_mem_term _LIBIJG8_jpeg_mem_term
#define jpeg_natural_order _LIBIJG8_jpeg_natural_order
#define jpeg_new_colormap _LIBIJG8_jpeg_new_colormap
#define jpeg_open_backing_store _LIBIJG8_jpeg_open_backing_store
#define jpeg_quality_scaling _LIBIJG8_jpeg_quality_scaling
#define jpeg_read_coefficients _LIBIJG8_jpeg_read_coefficients
#define jpeg_read_header _LIBIJG8_jpeg_read_header
#define jpeg_read_raw_data _LIBIJG8_jpeg_read_raw_data
#define jpeg_read_scanlines _LIBIJG8_jpeg_read_scanlines
#define jpeg_resync_to_restart _LIBIJG8_jpeg_resync_to_restart
#define jpeg_save_markers _LIBIJG8_jpeg_save_markers
#define jpeg_set_colorspace _LIBIJG8_jpeg_set_colorspace
#define jpeg_set_defaults _LIBIJG8_jpeg_set_defaults
#define jpeg_set_linear_quality _LIBIJG8_jpeg_set_linear_quality
#define jpeg_set_marker_processor _LIBIJG8_jpeg_set_marker_processor
#define jpeg_set_quality _LIBIJG8_jpeg_set_quality
#define jpeg_simple_lossless _LIBIJG8_jpeg_simple_lossless
#define jpeg_simple_progression _LIBIJG8_jpeg_simple_progression
#define jpeg_start_compress _LIBIJG8_jpeg_start_compress
#define jpeg_start_decompress _LIBIJG8_jpeg_start_decompress
#define jpeg_start_output _LIBIJG8_jpeg_start_output
#define jpeg_std_error _LIBIJG8_jpeg_std_error
#define jpeg_std_message_table _LIBIJG8_jpeg_std_message_table
#define jpeg_stdio_dest _LIBIJG8_jpeg_stdio_dest
#define jpeg_stdio_src _LIBIJG8_jpeg_stdio_src
#define jpeg_suppress_tables _LIBIJG8_jpeg_suppress_tables
#define jpeg_write_coefficients _LIBIJG8_jpeg_write_coefficients
#define jpeg_write_m_byte _LIBIJG8_jpeg_write_m_byte
#define jpeg_write_m_header _LIBIJG8_jpeg_write_m_header
#define jpeg_write_marker _LIBIJG8_jpeg_write_marker
#define jpeg_write_raw_data _LIBIJG8_jpeg_write_raw_data
#define jpeg_write_scanlines _LIBIJG8_jpeg_write_scanlines
#define jpeg_write_tables _LIBIJG8_jpeg_write_tables
#define jround_up _LIBIJG8_jround_up
#define jzero_far _LIBIJG8_jzero_far

