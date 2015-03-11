#include "edfparser.h"
#include <cstdlib>


// edf_hdr_struct is defined in edflib, so here is friend operator only
bool edfhdr_cmp(const edf_hdr_struct left, const edf_hdr_struct right)
{
    return (left.filetype == right.filetype) &&
            (left.edfsignals == right.edfsignals) &&
            (left.file_duration == right.file_duration) &&
            (left.startdate_day == right.startdate_day) &&
            (left.startdate_month == right.startdate_month) &&
            (left.startdate_year == right.startdate_year) &&
            (left.starttime_subsecond == right.starttime_subsecond) &&
            (left.starttime_second == right.starttime_second) &&
            (left.starttime_minute == right.starttime_minute) &&
            (left.starttime_hour == right.starttime_hour) &&
            !(std::strcmp(left.patient,right.patient)) &&
            !(std::strcmp(left.patientcode,right.patientcode));
}

EDF_file edfParser::parseEdf(std::string path)
{
	EDF_file file;

	// Open file and read header
	if (edfopen_file_readonly(path.c_str(), &file.header, EDFLIB_READ_ALL_ANNOTATIONS))
	{
		switch(file.header.filetype)
		{
			case EDFLIB_MALLOC_ERROR                : fprintf(stderr,"\nmalloc error\n\n");
				break;
			case EDFLIB_NO_SUCH_FILE_OR_DIRECTORY   : fprintf(stderr,"\ncan not open file, no such file or directory\n\n");
				break;
			case EDFLIB_FILE_CONTAINS_FORMAT_ERRORS : fprintf(stderr,"\nthe file is not EDF(+) or BDF(+) compliant\n"
															 "(it contains format errors)\n\n");
				break;
			case EDFLIB_MAXFILES_REACHED            : fprintf(stderr,"\ntoo many files opened\n\n");
				break;
			case EDFLIB_FILE_READ_ERROR             : fprintf(stderr,"\na read error occurred\n\n");
				break;
			case EDFLIB_FILE_ALREADY_OPENED         : fprintf(stderr,"\nfile has already been opened\n\n");
				break;
			default                                 : fprintf(stderr,"\nunknown error\n\n");
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
			fprintf(stderr,"\nerror: edf_get_annotations()\n");
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
			fprintf(stderr,"\nerror: edf_read_physical_samples()\n");
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
