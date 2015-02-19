//TEST FRAMEWORK EXAMPLE
//
#include "test_framework.h"
//Class which will be tested
class Sum {
    int m_a,  m_b;
public:
    Sum(int x, int y) : m_a(x), m_b(y) {}
    int op() {
        return m_a + m_b;
    }

};
//Mock adapter for this class
class SumMock: public AbstractMock<VarVect<int>, int, int>
{
    Sum *m_sum;
public:

    SumMock(const VarVect<int, int> &m_in) : AbstractMock(m_in) {
        m_sum = new Sum(std::get<0>(m_in), std::get<1>(m_in));
    }
    VarVect<int> getOutput() {
        int val = m_sum->op();
        return std::tie(val);
    }
    ~SumMock() {
        delete m_sum;
    }

};

//Test adapter for this class
class SumTest: public AbstractTest<VarVect<int>, int, int>
{
public:
    SumTest(TestMode mode, SumMock& mock) : AbstractTest("Sum test", mode, mock) {}
    bool checker(const VarVect<int > &outval) override //checker
    {
        int oval, xin, yin;
        std::tie(xin, yin) = m_mock.m_input;
        oval = std::get<0>(outval);
        return (oval== xin  +yin);
        return (std::get<0>(outval) == (std::get<0>(m_mock.m_input) + std::get<1>(m_mock.m_input)));
    }
};


int main() {

    SumMock mock1(std::make_tuple(5, 5));
    SumMock mock2(std::make_tuple(10, 11));
    SumTest SumTest1(EXP_MODE, mock1);
    SumTest1.setOutput(std::make_tuple(10));
    SumTest SumTest2(CHECKER_MODE, mock2);

    SumTest1.run();
    SumTest2.run();
    return 0;
}
