#include "testas.h"
#include "konteineriai.h"
#include "timer.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int DYDZIAI[] = {1000, 10000, 100000, 1000000, 10000000};

template <typename C>
void testuotiVienaKonteineri(const string &pavadinimas) {
    cout << "\n### " << pavadinimas << "\n\n";
    cout << "| Irasu | Nuskaitymas | Dalinimas | Rusiavimas | Isvedimas | Viso |\n";
    cout << "|---|---|---|---|---|---|\n";
    cout << fixed << setprecision(4);
    for (int n : DYDZIAI) {
        string failas = "studentai" + to_string(n) + ".txt";
        C s, vargsiukai, kietiakiai;
        Timer t;
        if (!skaitytiKonteineri(failas, s)) {
            cout << "| " << n << " | failas nerastas - pirma pasirinkite meniu 5 |\n";
            continue;
        }
        double nuskaitymas = t.elapsed();
        t.reset();
        dalintiKonteineri(s, vargsiukai, kietiakiai);
        double dalinimas = t.elapsed();
        s.clear();
        t.reset();
        rusiuotiKonteineri(vargsiukai);
        rusiuotiKonteineri(kietiakiai);
        double rusiavimas = t.elapsed();
        t.reset();
        rasytiKonteineri(vargsiukai, "vargsiukai.txt");
        rasytiKonteineri(kietiakiai, "kietiakiai.txt");
        double isvedimas = t.elapsed();
        cout << "| " << n << " | " << nuskaitymas << " | " << dalinimas << " | "
             << rusiavimas << " | " << isvedimas << " | "
             << nuskaitymas + dalinimas + rusiavimas + isvedimas << " |" << endl;
    }
}
void testuotiKonteinerius() {
    testuotiVienaKonteineri<vector<studentas>>("std::vector");
    testuotiVienaKonteineri<list<studentas>>("std::list");
}
