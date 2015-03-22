#include "dataprocessor.h"



abstractDataProcessor::~abstractDataProcessor()
{

}

customDataProcessor::~customDataProcessor()
{

}

std::vector<MPoint> customDataProcessor::getData()
{
    std::vector <MPoint> res;
    const double barrier_val = 50.0f;
    auto edf_it = m_data.edf_data.signals.begin();
    for (auto nbe_it = m_data.nbe_data.begin(); nbe_it != m_data.nbe_data.end()
                                                && edf_it != m_data.edf_data.signals.end();
                                                ++nbe_it, ++edf_it) {

        MPoint tmp;
        for (int i = 0; i < 3; ++i) {
            tmp.norm[i] = nbe_it->norm[i];
            tmp.vec3[i] = nbe_it->coords[i];

        }
        tmp.isBlack  = false;
        if (edf_it->getAmpl() > barrier_val) {
            tmp.isBlack = true;
        }
        res.push_back(tmp);
    }
    return res;
}
