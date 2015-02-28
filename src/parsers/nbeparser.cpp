#include <nbeparser.h>
#include <iostream>
#include <fstream>
enum
{
    MAX_LINE_LEN = 200,
    USELESS_STRING_CNT = 6,
    USELESS_WORDS_BEGIN_CNT = 10,
    USELESS_WORDS_END_CNT = 14
};

std::vector<HeadCoord> nbeParser::parseNbe(std::string path) {
    char tmpline[MAX_LINE_LEN];
    double b;
    std::vector<HeadCoord> data;
    HeadCoord HeadData;

    std::ifstream F;
    F.open(path, std::ios::in);
    if (!F.is_open()) {

        throw  std::string("Bad File") + path;
    }

    //read not useful strings
    for (int i=0; i<USELESS_STRING_CNT; i++)
        F.getline(tmpline, MAX_LINE_LEN);

    //read not useful words in the first informative string
    for (int i=0;i<USELESS_WORDS_BEGIN_CNT;i++)
        F>>tmpline;

    //read our values and write them in structure
    F>>b;
    HeadData.coords[0]=b;
    F>>b;
    HeadData.coords[1]=b;
    F>>b;
    HeadData.coords[2]=b;
    F>>b;
    HeadData.norm[0]=b;
    F>>b;
    HeadData.norm[1]=b;
    F>>b;
    HeadData.norm[2]=b;
    F>>b;
    HeadData.dir[0]=b;
    F>>b;
    HeadData.dir[1]=b;
    F>>b;
    HeadData.dir[2]=b;
    F>>b;
    HeadData.loc[0]=b;
    F>>b;
    HeadData.loc[1]=b;
    F>>b;
    HeadData.loc[2]=b;

    data.push_back(HeadData);

    //again useless symbols
    for (int i=0;i<14;i++)
        F>>tmpline;

    while (!F.eof())
    {
        //read not useful words in the informative string
        for (int i=0;i<USELESS_WORDS_BEGIN_CNT;i++)
            F>>tmpline;

        //now we gonna read and write
        F>>b;
        HeadData.coords[0]=b;
        F>>b;
        HeadData.coords[1]=b;
        F>>b;
        HeadData.coords[2]=b;
        F>>b;
        HeadData.norm[0]=b;
        F>>b;
        HeadData.norm[1]=b;
        F>>b;
        HeadData.norm[2]=b;
        F>>b;
        HeadData.dir[0]=b;
        F>>b;
        HeadData.dir[1]=b;
        F>>b;
        HeadData.dir[2]=b;
        F>>b;
        HeadData.loc[0]=b;
        F>>b;
        HeadData.loc[1]=b;
        F>>b;
        HeadData.loc[2]=b;
        //end of exercise

        //again useless symbols
        for (int i=0;i<USELESS_WORDS_END_CNT;i++)
            F>>tmpline;

        data.push_back(HeadData);
    }

    //delete last wrong extra data
    data.erase(data.begin()+data.size()-1);

    F.close();

    return data;

}


std::vector<HeadCoord> nbeParser::getData()
{
    std::vector<HeadCoord> res;
    for (auto it : m_fnames) {
        std::vector<HeadCoord> tmpvect = parseNbe(it);
        res.insert(res.end(), tmpvect.begin(), tmpvect.end());

    }
    return res;
}
