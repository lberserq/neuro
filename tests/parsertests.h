#ifndef PARSERTESTS_H
#define PARSERTESTS_H
#include <nbeparser.h>
#include <dicomparser.h>
#include "test_framework.h"

class nbeMock : public AbstractMock<std::vector<HeadCoord>, std::list<std::string> >
{
    nbeParser *parser;
public:
    nbeMock(const VarVect<std::list<std::string> > &m_input) :AbstractMock(m_input), parser(NULL) {
        std::list<std::string> res;

        res = std::get<0>(m_input);
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



class dicomMock : public AbstractMock<std::vector<DicomData>, std::list<std::string> >
{
    dicomParser *parser;
public:
    dicomMock(const VarVect<std::list<std::string> > &m_input) :AbstractMock(m_input), parser(NULL) {
        std::list<std::string> res;

        res = std::get<0>(m_input);
        parser = new dicomParser(res);
    }

    std::vector<DicomData> getOutput() override {
        return parser->getData();
    }

    ~dicomMock() {
       delete parser;
       parser = NULL;
    }
};


class dicomTest: public AbstractTest<std::vector<DicomData>, std::list<std::string> > {
public:
    dicomTest(const TestMode &mode, dicomMock &mock) : AbstractTest("dicom parser test", mode, mock) {}
    bool checker(const std::vector<DicomData> &outval)  override{
        //return (outval.size() == 67);
        return (outval[0].ImageData.h == outval[0].ImageData.w && outval[0].ImageData.w == 512);
    }
};


#endif // PARSERTESTS_H
