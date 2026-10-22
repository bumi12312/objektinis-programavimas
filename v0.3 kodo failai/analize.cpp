#include "analize.h"
#include "studentas.h"
#include "ivestis.h"
#include "isvestis.h"
#include "kategorijos.h"
#include "timer.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void spartosAnalize() {
    const int dydziai[] = {1000, 10000, 100000, 1000000, 10000000};
    cout << "\n" << left << setw(12) << "Irasu"
         << setw(14) << "Nuskaitymas"
         << setw(14) << "Dalinimas"
         << setw(14) << "Rusiavimas"
         << setw(14) << "Isvedimas"
         << "Viso (s)\n";
    cout << string(80, '-') << "\n" << fixed << setprecision(4);
    for (int n : dydziai) {
        string failas = "studentai" + to_string(n) + ".txt";
        vector<studentas> s;
        Timer t;
        if (!nuskaitytiFaila(failas, s)) {
            cout << left << setw(12) << n << "failas nerastas (pirma pasirinkite 5)\n";
            continue;
        }
        double nuskaitymas = t.elapsed();
        t.reset();
        Kategorijos k = dalintiStudentus(s);
        double dalinimas = t.elapsed();
        t.reset();
        auto pagalBala = [](const studentas &a, const studentas &b) {
            return a.galutinisVid < b.galutinisVid;
        };
        sort(k.vargsiukai.begin(), k.vargsiukai.end(), pagalBala);
        sort(k.kietiakiai.begin(), k.kietiakiai.end(), pagalBala);
        double rusiavimas = t.elapsed();
        t.reset();
        irasytiIFaila(k.vargsiukai, "vargsiukai" + to_string(n) + ".txt");
        irasytiIFaila(k.kietiakiai, "kietiakiai" + to_string(n) + ".txt");
        double isvedimas = t.elapsed();
        cout << left << setw(12) << n
             << setw(14) << nuskaitymas
             << setw(14) << dalinimas
             << setw(14) << rusiavimas
             << setw(14) << isvedimas
             << nuskaitymas + dalinimas + rusiavimas + isvedimas << "\n";
    }
}
