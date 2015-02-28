
#include "test_framework.h"
#include "parsertests.h"

int main() {


    std::list<std::string> lst;
    lst.push_back("test_file.dcm");
    dicomMock mock(make_tuple(lst));
    dicomTest dicom_test(CHECKER_MODE, mock);
    dicom_test.run();
    return 0;
}


