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
};


bool edfhdr_cmp(const edf_hdr_struct &left, const edf_hdr_struct &right); //magic how it works


struct EDF_file
{
    edf_hdr_struct header;
    std::vector<edf_annotation_struct> annotations;
    std::vector<edf_signal_struct> signals;

    friend bool operator == (const EDF_file &left, const EDF_file &right)
    {

        return edfhdr_cmp(left.header, right.header);
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
