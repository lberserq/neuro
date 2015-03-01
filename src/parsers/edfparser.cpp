#include "edfparser.h"
#include <cstdlib>


EDF_file edfParser::parseEdf(std::string path)
{
	EDF_file file;

	// Open file and read header
	if (edfopen_file_readonly(path.c_str(), &file.header, EDFLIB_READ_ALL_ANNOTATIONS))
	{
		switch(file.header.filetype)
		{
			case EDFLIB_MALLOC_ERROR                : printf("\nmalloc error\n\n");
				break;
			case EDFLIB_NO_SUCH_FILE_OR_DIRECTORY   : printf("\ncan not open file, no such file or directory\n\n");
				break;
			case EDFLIB_FILE_CONTAINS_FORMAT_ERRORS : printf("\nthe file is not EDF(+) or BDF(+) compliant\n"
															 "(it contains format errors)\n\n");
				break;
			case EDFLIB_MAXFILES_REACHED            : printf("\ntoo many files opened\n\n");
				break;
			case EDFLIB_FILE_READ_ERROR             : printf("\na read error occurred\n\n");
				break;
			case EDFLIB_FILE_ALREADY_OPENED         : printf("\nfile has already been opened\n\n");
				break;
			default                                 : printf("\nunknown error\n\n");
				break;
		}
		return file;
	}

	int hdl = file.header.handle;

	// Read annotations
	for (int i = 0; i < file.header.annotations_in_file; i++)
	{
		if (edf_get_annotation(hdl, i, &file.annotations[i]))
		{
			printf("\nerror: edf_get_annotations()\n");
			edfclose_file(hdl);
			return file;
		}
	}

	// Read samples
	for (int i = 0; i < file.header.edfsignals; i++)
	{
		file.signals[i].samples = (double *)malloc(sizeof(double[file.header.signalparam[i].smp_in_datarecord]));
		int n = edfread_physical_samples(hdl, i, file.header.signalparam[i].smp_in_datarecord, file.signals[i].samples);
		if (n < file.header.signalparam[i].smp_in_datarecord)
		{
			printf("\nerror: edf_read_physical_samples()\n");
			edfclose_file(hdl);
			return file;
		}
		file.signals[i].sample_num = file.header.signalparam[i].smp_in_datarecord;
	}

	edfclose_file(hdl);
    return file;

}

std::vector<EDF_file> edfParser::getData()
{
	std::vector<EDF_file> res;
    for (auto it :m_fnames)
	{
        //std::vector<EDF_file> tmpvect = parseEdf(*it); Andrew it`s your legacy code and it`s failed to build
        //res.insert(res.end(), tmpvect.begin(), tmpvect.end());
        EDF_file tmp = parseEdf(it);
        res.push_back(tmp);

	}
	return res;
}
