#include "test_framework.h"
#include "parsertests.h"

int main() {


	std::list<std::string> lst;
	lst.push_back("test_file.edf");
	edfMock mock(std::make_tuple(lst));
	edfTest edf_test(CHECKER_MODE, mock);
	edf_test.run();
	return 0;
}
