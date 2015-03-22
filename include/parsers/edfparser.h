#ifndef EDFPARSER_H
#define EDFPARSER_H

extern "C" {
#include <edflib/edflib.h>
}
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <cmath>


struct edf_signal_struct
{
    double* samples;
    int sample_num;

    edf_signal_struct(const edf_signal_struct &right) {
        samples = new double[right.sample_num];
        sample_num = right.sample_num;
    }

    edf_signal_struct& operator = (const edf_signal_struct& right) {
        delete [] samples;
        sample_num = right.sample_num;
        samples = new double[sample_num];
        std::copy(right.samples, right.samples + right.sample_num, this->samples);
        return *this;
    }

    double getAmpl() {
        double a_max = 0.0f;
        for (int i = 0; i < sample_num; ++i) {
            a_max = std::max(a_max, std::abs(samples[i]));
        }
        return a_max;
    }

    edf_signal_struct() : samples(NULL), sample_num(0)
    {}
    ~edf_signal_struct()
    {
        if (samples)
            delete [] samples;
    }
};


bool edfhdr_cmp(const edf_hdr_struct &left, const edf_hdr_struct &right); //magic how it works


struct EDF_file
{   //refactor this class where is operators = and Copy constructor
    //
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
