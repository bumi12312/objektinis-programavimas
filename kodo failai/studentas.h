#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

struct studentas {
    std::string vardas = "";
    std::string pavarde = "";
    std::vector<int> nd;
    int egz = 0;
    float galutinisVid = 0;
    float galutinisMed = 0;
};

struct Kategorijos {
    std::vector<studentas> vargsiukai;
    std::vector<studentas> kietiakiai;
};

void apskaiciuotiGalutini(studentas &s);

#endif
