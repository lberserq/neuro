
#include "test_framework.h"
#include "parsertests.h"

int main() {


    std::list<std::string> lst;
    lst.push_back("test_file.nbe");
    nbeMock mock(std::make_tuple(lst));
    nbeTest nbe_test(CHECKER_MODE, mock);
    nbe_test.run();
    return 0;
}

