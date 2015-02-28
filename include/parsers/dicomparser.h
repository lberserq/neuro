#ifndef DICOMPARSER_H
#define DICOMPARSER_H
#include <vector>
#include <list>
#include <string>
#include <cmath>
#include <iostream>
const double m_eps = 1e-7;
struct DicomImData
{
    char *pixeldata;
    int pixeldata_length;
    int w;
    int h;
    int precision;
    int signedness;
    int ncomps;
    int nframes;
    int bpp;
    friend bool operator == (const DicomImData left, const DicomImData right) {
        if (left.h != right.h
                || left.w != right.h
                || left.bpp != right.bpp
                || left.precision != right.precision
                || left.signedness != right.signedness
                || left.ncomps != right.ncomps
                || left.nframes != right.nframes
                || left.pixeldata_length != right.pixeldata_length) {
            return false;
        }

        for (int i = 0; i < left.pixeldata_length; i++) {
                if (left.pixeldata[i] != right.pixeldata[i]) {
                    return false;
                }
            }
            return true;
        }
    friend bool operator != (const DicomImData left, const DicomImData right) {
        return (!(left == right));
    }
};

struct DicomData{
    std::vector<double> ImagePos;
    std::vector<double> ImageOrient;
    std::string patName;
    double sliceLoc;
    int patId;
    DicomImData imageData;
    friend bool operator == (const DicomData left, const DicomData right) {
        if (left.imageData != right.imageData) {
            return false;
        }
        for (int i = 0; i < 2; i++) {
            if (!(left.ImagePos[i] == right.ImagePos[i]
                  && left.ImageOrient[i] == right.ImageOrient[i]
                  && left.patName == right.patName
                  && left.patId == right.patId
                  && std::abs(left.sliceLoc - right.sliceLoc) < m_eps)) {

                return false;
            }
        }
        return true;
    }
};



class dicomParser
{
    std::list<std::string> m_fnames;
    // const std::list<std::string> &m_dirname;
    DicomData getValname(const std::string &fname);
public:
    dicomParser(const std::list<std::string> &fnames) : m_fnames(fnames) {
        std::cerr << *m_fnames.begin() << std::endl;
    }
    std::vector<DicomData> getData();
    std::vector<DicomImData> getImVal();
    //static std::vector<DicomData> getValFromDir(const std::string &m_dirname);

};

#endif // DICOMPARSER_H
