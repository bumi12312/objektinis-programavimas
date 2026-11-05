#ifndef STRATEGIJOS_H
#define STRATEGIJOS_H

#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include "studentas.h"

inline bool yraVargsiukas(const studentas &s) { return s.galutinisVid < 5.0; }

template <typename C>
void dalintiS1(C &s, C &vargsiukai, C &kietiakiai) {
    for (const auto &stud : s) {
        if (yraVargsiukas(stud)) vargsiukai.push_back(stud);
        else                      kietiakiai.push_back(stud);
    }
}
template <typename C>
void dalintiS2(C &s, C &vargsiukai, C & /*nenaudojamas*/)
{
    for (auto it = s.begin(); it != s.end();) 
    {
        if (yraVargsiukas(*it)) 
        {
            vargsiukai.push_back(*it);
            it = s.erase(it);
        } else {
            ++it;
        }
    }
}

inline void dalintiVekS3a(std::vector<studentas> &s, std::vector<studentas> &vargsiukai,
                          std::vector<studentas> &)
{
    std::copy_if(s.begin(), s.end(), std::back_inserter(vargsiukai), yraVargsiukas);
    s.erase(std::remove_if(s.begin(), s.end(), yraVargsiukas), s.end());
}
inline void dalintiVekS3b(std::vector<studentas> &s, std::vector<studentas> &vargsiukai,
                          std::vector<studentas> &)
{
    auto riba = std::partition(s.begin(), s.end(),
                               [](const studentas &x) { return !yraVargsiukas(x); });
    vargsiukai.assign(std::make_move_iterator(riba), std::make_move_iterator(s.end()));
    s.erase(riba, s.end());
}
inline void dalintiVekS3c(std::vector<studentas> &s, std::vector<studentas> &vargsiukai,
                          std::vector<studentas> &)
{
    auto riba = std::stable_partition(s.begin(), s.end(),
                                      [](const studentas &x)
{ return !yraVargsiukas(x); });
    vargsiukai.assign(std::make_move_iterator(riba), std::make_move_iterator(s.end()));
    s.erase(riba, s.end());
}
inline void dalintiListS3(std::list<studentas> &s, std::list<studentas> &vargsiukai,
                          std::list<studentas> &) 
{
    for (auto it = s.begin(); it != s.end();) {
        auto sekantis = std::next(it);
        if (yraVargsiukas(*it)) vargsiukai.splice(vargsiukai.end(), s, it);
        it = sekantis;
    }
}

#endif
