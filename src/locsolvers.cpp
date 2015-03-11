#include "locsolvers.h"

#include <algorithm>

class LineComps
{
public:
    static bool upperLine(point p1, point p2, point p3) {
        return ((p1.coords[0] * (p2.coords[1] - p3.coords[1])  + p2.coords[0] * (p3.coords[1] - p1.coords[1])
                + p3.coords[0] * (p1.coords[1] - p2.coords[1])) < 0);
    }

    static bool downerLine(point p1, point p2, point p3) {
        return ((p1.coords[0] * (p2.coords[1] - p3.coords[1])  + p2.coords[0] * (p3.coords[1] - p1.coords[1])
                + p3.coords[0] * (p1.coords[1] - p2.coords[1])) > 0);
    }



};

void naiveGrahamSolver::grahamAndrew()// A.M Andrew optimization for Graham Algorithm
{
    if (m_vct.size()  < 3) {
        m_vct.clear();
        return;
    }
    std::sort(m_vct.begin(), m_vct.end());
    std::vector<point> up, down;
    point left = m_vct.front(); //left down point
    point right = m_vct.back(); // right up point
    up.push_back(left);
    down.push_back(left);
    for (auto pnt: m_vct) {
        if (pnt == right || LineComps::upperLine(left, pnt, right)) {
            while (up.size() >= 2 && !LineComps::upperLine(up[up.size() - 2], up.back(), pnt)) {
                up.pop_back();
            }
            up.push_back(pnt);
        }
        if (pnt == right || LineComps::downerLine(left, pnt, right)) {
            while (down.size() >= 2 && !LineComps::upperLine(down[up.size() - 2], down.back(), pnt)) {
                down.pop_back();
            }
            down.push_back(pnt);
        }
    }
    m_vct.clear();
    for (auto it = up.begin(); it < up.end(); it++) {
        m_vct.push_back(*it);
    }
    for (auto it = down.rbegin(); it < down.rend(); it++) {
        m_vct.push_back(*it);
    }
}

double naiveGrahamSolver::getSquare() {
    double res = 0.0f;
    for (auto it = m_vct.begin(); it < m_vct.end(); it++) {
        point curr = *it;
        point next = (it == m_vct.end()) ? m_vct.front() : *std::next(it);
        res += (curr.coords[0] + next.coords[1]) *(curr.coords[1] - next.coords[1]);
    }
    return res / 2.0f;
}
