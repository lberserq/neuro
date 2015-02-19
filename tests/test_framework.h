#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H
#include <vector>
#include <iostream>
#include <string>
#include <tuple>
enum TestMode
{
    EXP_MODE = 0, // mode test input + right answer
    CHECKER_MODE = 1, //mode input + checker
};

template <typename ... Types>
using VarVect = std::tuple<Types ...>;

template <typename Res, typename ... Types>
class AbstractMock
{
public:
    const VarVect<Types ...>& m_input;
    AbstractMock(const VarVect<Types ...>& input) : m_input(input) {}
    virtual Res getOutput() = 0;
};
template <typename Res, typename ... Types>

class AbstractTest
{

    const std::string m_name;
    TestMode m_mode;
protected:
    AbstractMock<Res, Types ...> &m_mock;
    Res m_output;
public:
    AbstractTest(const std::string &testName, TestMode mode, AbstractMock<Res, Types ...> &mock): m_name(testName), m_mode(mode), m_mock(mock) {}
    virtual bool checker(const Res &outval) = 0;
    void setOutput(const Res &output) {
        m_output = output;
    }

    bool run() {
        Res output = m_mock.getOutput();
        bool res = false;
        switch (m_mode) {
        case EXP_MODE:
            res = (output == m_output);
            break;
        case CHECKER_MODE:
            res = checker(output);
            break;
        default:
            break;
        }
        std::cerr << "TEST " << m_name;
        if (!res) {
            std::cerr << " FAILED!!!!";
        } else {
            std::cerr << " PASSED";
        }
        std::cerr << std::endl;
    }

};
/*
 *
 *
 *
 *
 * */

#endif // TEST_FRAMEWORK_H
