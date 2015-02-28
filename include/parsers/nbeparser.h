#ifndef NBEPARSER_H
#define NBEPARSER_H
#include <vector>
#include <list>
#include <string>
struct HeadCoord
{
    double coords[3];
    double norm[3];
    double dir[3];
    double loc[3];
    bool operator == (const HeadCoord right) {
        for (int i = 0; i < 2; i++) {
            if (!(coords[i] == right.coords[i] && norm[i] == right.norm[i]
                  && dir[i] == right.dir[i]
                  && loc[i] == right.loc[i])) {
                return false;
            }
        }
        return true;
    }
    friend bool operator == (const HeadCoord left, const HeadCoord right) {
        for (int i = 0; i < 2; i++) {
            if (!(left.coords[i] == right.coords[i]
                  && left.norm[i] == right.norm[i]
                  && left.dir[i] == right.dir[i]
                  && left.loc[i] == right.loc[i])) {
                return false;
            }
        }
        return true;
    }
};

class nbeParser
{
    std::vector<HeadCoord> parseNbe(std::string path);
    std::list<std::string> m_fnames;
public:
    nbeParser(std::list<std::string> file_names) : m_fnames(file_names) {
    }
    std::vector<HeadCoord> getData();
};

#endif // NBEPARSER_H
