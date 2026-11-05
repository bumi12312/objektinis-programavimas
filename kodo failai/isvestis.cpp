#include "isvestis.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

void rodytiRezultatus(const vector<studentas> &s, int pasirinkimas) {
    if (s.empty()) {
        cout << "Duomenu nera - ivesk, sugeneruok arba nuskaityk duomenis.\n";
        return;
    }
    vector<studentas> rusiavimas = s;
    sort(rusiavimas.begin(), rusiavimas.end(),
        [](const studentas &a, const studentas &b) {
            return a.pavarde < b.pavarde;
        });
    cout << "\n" << left << setw(16) << "Vardas" << setw(16) << "Pavarde";
    if (pasirinkimas == 1) {
        cout << "Galutinis (Vid.)";
    } else if (pasirinkimas == 2) {
        cout << "Galutinis (Med.)";
    } else {
        cout << "Galutinis (Vid.) / Galutinis (Med.)";
    }
    cout << "\n";
    cout << "--------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    for (const auto &stud : rusiavimas) {
        cout << left << setw(16) << stud.vardas << setw(16) << stud.pavarde;
        if (pasirinkimas == 1) {
            cout << stud.galutinisVid;
        } else if (pasirinkimas == 2) {
            cout << stud.galutinisMed;
        } else {
            cout << left << setw(24) << stud.galutinisVid << stud.galutinisMed;
        }
        cout << "\n";
    }
}

void irasytiIFaila(const vector<studentas> &v, const string &pavadinimas) {
    ofstream out(pavadinimas);
    out << fixed << setprecision(2);
    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << "Galutinis (Vid.)\n";
    for (const auto &stud : v) {
        out << left << setw(20) << stud.vardas << setw(20) << stud.pavarde
            << stud.galutinisVid << "\n";
    }
    out.close();
}
