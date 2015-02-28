#include "dicomparser.h"
#include <dicomsdl/dicom.h>
std::vector<DicomData> dicomParser::getData()
{
    std::vector<DicomData> res;

    for (auto it : m_fnames) {
        DicomData tmp =  getValname(it);
        res.push_back(tmp);
    }
    return res;
}



DicomData dicomParser::getValname(const std::string &fname)
{
    dicom::dicomfile *file = dicom::open_dicomfile(fname.c_str());
    if (!file) {
        throw std::string("Error") + std::string(dicom::get_error_message());
    }
    DicomData res;
    res.patId = (*file)["PatientID"];
    res.patName = std::string((*file)["PatientName"]);
    res.sliceLoc = (*file)["SliceLocation"];
    res.ImageOrient =  (*file)["ImagePositionPatient"];
    res.ImagePos = (*file)["ImageOrientationPatient"];

    file->get_image_info(&res.imageData.w,
                         &res.imageData.h,
                         &res.imageData.precision,
                         &res.imageData.signedness,
                         &res.imageData.ncomps,
                         &res.imageData.bpp,
                         &res.imageData.nframes);
    file->get_pixeldata_a(&res.imageData.pixeldata, &res.imageData.pixeldata_length);
    delete file;
    return res;
}


