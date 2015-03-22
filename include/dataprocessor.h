#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H
#include "allparsers.h"

struct PatData
{
   EDF_file edf_data;
   std::vector<HeadCoord> nbe_data;
   std::vector<DicomData> dicom_data;
};

struct MPoint
{
    static double m_eps;
    bool isBlack;
    double vec3[3];
    double norm[3];
    friend bool operator == (const struct MPoint &left,  const struct MPoint &right) {
        if (left.isBlack != right.isBlack) {
            return false;
        }
        for (int i = 0; i < 3; i++) {
            if (std::abs(left.vec3[i] - right.vec3[i]) > m_eps ||
                    std::abs(left.vec3[i] - right.vec3[i]) > m_eps) {
                return false;
            }
        }
        return true;
    }
};
double MPoint::m_eps = 1e-7;

class abstractDataProcessor
{
protected:
    PatData m_data;
    //function set the isBlack or not in
public:
    abstractDataProcessor(const PatData& data) : m_data(data) {}
    virtual std::vector<MPoint> getData() = 0;
    virtual ~abstractDataProcessor();
};


class customDataProcessor: public abstractDataProcessor {
public:
    customDataProcessor(const PatData& data) : abstractDataProcessor(data) {}
    std::vector<MPoint> getData() override;
    virtual ~customDataProcessor();
};

#endif // DATAPROCESSOR_H
