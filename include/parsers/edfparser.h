#ifndef EDFPARSER_H
#define EDFPARSER_H

extern "C" {
#include <edflib/edflib.h>
}
#include <vector>
#include <list>
#include <string>
#include <cstring>


struct edf_signal_struct
{
	double* samples;
	int sample_num;

	edf_signal_struct() : samples(NULL), sample_num(0)
	{}
	~edf_signal_struct()
	{
		if (samples)
			free(samples);
	}
    friend bool operator == (const edf_hdr_struct left, const edf_hdr_struct right);
};

// edf_hdr_struct is defined in edflib, so here is friend operator only
bool operator == (const edf_hdr_struct left, const edf_hdr_struct right)
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

struct EDF_file
{
	edf_hdr_struct header;
	std::vector<edf_annotation_struct> annotations;
	std::vector<edf_signal_struct> signals;

	friend bool operator == (const EDF_file left, const EDF_file right)
	{
		//return (left.header == right.header) &&
		//	   (left.annotations == right.annotations) && 
		//	   (left.signals == right.signals);

		return (left.header == right.header);
		// I think header determines all file
	}
};

class edfParser
{
	EDF_file parseEdf(std::string path);
	std::list<std::string> m_fnames;

	public:

	edfParser(std::list<std::string> file_names) : m_fnames(file_names) 
	{}
	std::vector<EDF_file> getData();
};
#endif // EDFPARSER_H
