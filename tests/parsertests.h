#ifndef PARSERTESTS_H
#define PARSERTESTS_H
#include "../nbeparser.h"
#include "test_framework.h"

class nbeMock : public AbstractMock<std::vector<HeadCoord>, std::list<std::string> >
{
    nbeParser *parser;
public:
    nbeMock(const VarVect<std::list<std::string> > &m_input) :AbstractMock(m_input), parser(NULL) {
        std::list<std::string> res;

        std::cerr << res.size() << '\n';
        res = std::get<0>(m_input);
        std::cerr << res.size() << '\n';
        parser = new nbeParser(res);
    }

    std::vector<HeadCoord> getOutput() override {
        return parser->getData();
    }

    ~nbeMock() {
       delete parser;
       parser = NULL;
    }
};


class nbeTest: public AbstractTest<std::vector<HeadCoord>, std::list<std::string> > {
public:
    nbeTest(const TestMode &mode, nbeMock &mock) : AbstractTest("Nbe parser test", mode, mock) {}
    bool checker(const std::vector<HeadCoord> &outval)  override{
        return (outval.size() == 67);

    }
};


#endif // PARSERTESTS_H
