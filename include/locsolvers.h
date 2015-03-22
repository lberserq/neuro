#ifndef LOCSOLVERS_H
#define LOCSOLVERS_H
#include <vector>
#include <cmath>

typedef struct s_point {

    static double m_eps;
    double coords[2];
    friend bool operator == (const struct s_point &a, const struct s_point &b) {
        for (int i = 0; i < 2; ++i) {
            if ((std::abs(a.coords[i] - b.coords[i])) > m_eps) {
                return false;
            }
        }

        return true;
    }
    friend bool operator < (const s_point &a, const s_point &b) {
        return a.coords[0] < b.coords[0] || (std::abs(a.coords[0] - b.coords[0]) < m_eps  && a.coords[1] < b.coords[1]);
    }
} point;

typedef struct t_point {

};

double point::m_eps = 1e-7;


class abstractLocSolver
{
protected:
    std::vector<point> m_vct;
public:
    abstractLocSolver(const std::vector<point> &vct) : m_vct(vct) {

    }

    virtual double getSquare() = 0;
};


class  naiveGrahamSolver: public abstractLocSolver
{
    void grahamAndrew();
public:
    naiveGrahamSolver(const std::vector<point> &vct) : abstractLocSolver(vct) {

    }
    double getSquare() override;
};

#endif // LOCSOLVERS_H
