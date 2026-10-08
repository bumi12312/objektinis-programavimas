#include "kategorijos.h"
#include "isvestis.h"
#include <iostream>
#include <algorithm>

using namespace std;

Kategorijos dalintiStudentus(const vector<studentas> &s) {
    Kategorijos k;
    for (const auto &stud : s) {
        if (stud.galutinisVid < 5.0)
            k.vargsiukai.push_back(stud);
        else
            k.kietiakiai.push_back(stud);
    }
    return k;
}

void kategorijos(const vector<studentas> &s) {
    if (s.empty()) {
        cout << "Duomenu nera - pirma nuskaityk arba sugeneruok duomenis.\n";
        return;
    }
    Kategorijos k = dalintiStudentus(s);

    auto pagalBala = [](const studentas &a, const studentas &b) {
        return a.galutinisVid < b.galutinisVid;
    };
    sort(k.vargsiukai.begin(), k.vargsiukai.end(), pagalBala);
    sort(k.kietiakiai.begin(), k.kietiakiai.end(), pagalBala);

    irasytiIFaila(k.vargsiukai, "vargsiukai.txt");
    irasytiIFaila(k.kietiakiai, "kietiakiai.txt");

    cout << "Vargsiukai (< 5.0): " << k.vargsiukai.size() << "\n";
    cout << "Kietiakiai (>= 5.0): " << k.kietiakiai.size() << "\n";
    cout << "Rezultatai irasyti i vargsiukai.txt ir kietiakiai.txt\n";
}
