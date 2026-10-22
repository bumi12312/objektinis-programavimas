#ifndef IVESTIS_H
#define IVESTIS_H

#include <string>
#include <vector>
#include "studentas.h"

void ivestiRankiniu(std::vector<studentas> &s);
bool nuskaitytiFaila(const std::string &failoPav, std::vector<studentas> &s);
void nuskaitytiIsFailo(std::vector<studentas> &s);
void generuotiAtsitiktinai(std::vector<studentas> &s);

#endif
