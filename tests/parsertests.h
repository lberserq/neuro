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
        return (outval[0].imageData.h == outval[0].imageData.w && outval[0].imageData.w == 512);
    }
};



class edfMock : public AbstractMock<std::vector<EDF_file>, std::list<std::string> >
{
	edfParser *parser;
public:
	edfMock(const VarVect<std::list<std::string> > &m_input) :AbstractMock(m_input), parser(NULL) {
		std::list<std::string> res;
		
		res = std::get<0>(m_input);
		parser = new edfParser(res);
	}

	std::vector<EDF_file> getOutput() override {
		return parser->getData();
	}

	~edfMock() {
		delete parser;
		parser = NULL;
	}
};


class edfTest: public AbstractTest<std::vector<EDF_file>, std::list<std::string> > {
public:
	edfTest(const TestMode &mode, edfMock &mock) : AbstractTest("Edf parser test", mode, mock) {}
	bool checker(const std::vector<EDF_file> &outval) override{
		return (outval.size() == 1);
	}
};


#endif // PARSERTESTS_H
