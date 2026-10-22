#ifndef KONTEINERIAI_H
#define KONTEINERIAI_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <list>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "studentas.h"

template <typename C>
bool skaitytiKonteineri(const std::string &failoPav, C &s) {
    std::ifstream failas(failoPav);
    if (!failas.is_open()) return false;
    std::string eilute;
    std::getline(failas, eilute);
    while (std::getline(failas, eilute)) {
        if (eilute.empty()) continue;
        studentas stud;
        std::istringstream iss(eilute);
        iss >> stud.vardas >> stud.pavarde;
        int balas;
        while (iss >> balas) stud.nd.push_back(balas);
        if (!stud.nd.empty()) {
            stud.egz = stud.nd.back();
            stud.nd.pop_back();
        }
        apskaiciuotiGalutini(stud);
        s.push_back(std::move(stud));
    }
    return true;
}

template <typename C>
void dalintiKonteineri(C &s, C &vargsiukai, C &kietiakiai) {
    for (auto &stud : s) {
        if (stud.galutinisVid < 5.0)
            vargsiukai.push_back(std::move(stud));
        else
            kietiakiai.push_back(std::move(stud));
    }
}

inline bool maziauPagalBala(const studentas &a, const studentas &b) {
    return a.galutinisVid < b.galutinisVid;
}
inline void rusiuotiKonteineri(std::vector<studentas> &v) {
    std::sort(v.begin(), v.end(), maziauPagalBala);
}
inline void rusiuotiKonteineri(std::list<studentas> &l) {
    l.sort(maziauPagalBala);
}

template <typename C>
void rasytiKonteineri(const C &v, const std::string &pavadinimas) {
    std::ofstream out(pavadinimas);
    out << std::fixed << std::setprecision(2);
    out << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde"
        << "Galutinis (Vid.)\n";
    for (const auto &stud : v) {
        out << std::left << std::setw(20) << stud.vardas << std::setw(20) << stud.pavarde
            << stud.galutinisVid << "\n";
    }
}
// 5) Rankinis ivedimas bet kokiam konteineriui + objekto adresas atmintyje
template <typename C>
void ivestiRankiniuSuAdresais(C &s) {
    using namespace std;
    int studSk;
    cout << "Studentu skaicius: ";
    cin >> studSk;
    cin.ignore();
    for (int i = 0; i < studSk; i++) {
        studentas stud;
        cout << "\n" << (i + 1) << "-as studentas\n";
        cout << "Vardas: ";
        cin >> stud.vardas;
        cout << "Pavarde: ";
        cin >> stud.pavarde;
        cin.ignore();
        cout << "Namu darbu balai (palikti tuscia, kad baigti):\n";
        while (true) {
            string eilute;
            getline(cin, eilute);
            if (eilute.empty()) break;
            try {
                stud.nd.push_back(stoi(eilute));
            } catch (const exception &) {
                cout << "Neteisinga reiksme, bandykite dar karta.\n";
            }
        }
        cout << "Egzamino rezultatas: ";
        cin >> stud.egz;
        cin.ignore();
        apskaiciuotiGalutini(stud);
        s.push_back(std::move(stud));
        cout << "Objekto adresas atmintyje: " << static_cast<const void *>(&s.back()) << "\n";
    }
}
template <typename C>
void rodytiSuAdresais(const C &s) {
    using namespace std;
    cout << "\n" << left << setw(16) << "Vardas" << setw(16) << "Pavarde"
         << setw(12) << "Galutinis" << "Adresas\n";
    cout << string(60, '-') << "\n" << fixed << setprecision(2);
    for (const auto &stud : s) {
        cout << left << setw(16) << stud.vardas << setw(16) << stud.pavarde
             << setw(12) << stud.galutinisVid
             << static_cast<const void *>(&stud) << "\n";
    }
}
#endif
