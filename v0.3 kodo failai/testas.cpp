#include "testas.h"
#include "konteineriai.h"
#include "timer.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int DYDZIAI[] = {1000, 10000, 100000, 1000000, 10000000};
const int BANDYMU = 3;  

struct Laikai {
    double nuskaitymas = 0;
    double dalinimas = 0;
    double rusiavimas = 0;
    double isvedimas = 0;
    double viso() const { return nuskaitymas + dalinimas + rusiavimas + isvedimas; }
};
template <typename C>
bool matuotiViena(int n, Laikai &l) {
    string failas = "studentai" + to_string(n) + ".txt";
    C s, vargsiukai, kietiakiai;
    Timer t;
    if (!skaitytiKonteineri(failas, s)) return false;
    l.nuskaitymas = t.elapsed();
    t.reset();
    dalintiKonteineri(s, vargsiukai, kietiakiai);
    l.dalinimas = t.elapsed();
    s.clear();
    t.reset();
    rusiuotiKonteineri(vargsiukai);
    rusiuotiKonteineri(kietiakiai);
    l.rusiavimas = t.elapsed();
    t.reset();
    rasytiKonteineri(vargsiukai, "vargsiukai.txt");
    rasytiKonteineri(kietiakiai, "kietiakiai.txt");
    l.isvedimas = t.elapsed();
    return true;
}
template <typename C>
void testuotiVienaKonteineri(const string &pavadinimas) {
    cout << "\n### " << pavadinimas << " (kiekvieno zingsnio vidurkis is "
         << BANDYMU << " bandymu)\n\n";
    cout << "| Irasu | Nuskaitymas | Dalinimas | Rusiavimas | Isvedimas | Viso |\n";
    cout << "|---|---|---|---|---|---|\n";
    cout << fixed << setprecision(4);
    for (int n : DYDZIAI) {
        Laikai suma;
        bool pavyko = true;
        for (int b = 0; b < BANDYMU; b++) {
            Laikai l;
            if (!matuotiViena<C>(n, l)) { pavyko = false; break; }
            suma.nuskaitymas += l.nuskaitymas;
            suma.dalinimas   += l.dalinimas;
            suma.rusiavimas  += l.rusiavimas;
            suma.isvedimas   += l.isvedimas;
        }
        if (!pavyko) {
            cout << "| " << n << " | failas nerastas - pirma pasirinkite meniu 5 |\n";
            continue;
        }
        cout << "| " << n << " | " << suma.nuskaitymas / BANDYMU
             << " | " << suma.dalinimas / BANDYMU
             << " | " << suma.rusiavimas / BANDYMU
             << " | " << suma.isvedimas / BANDYMU
             << " | " << suma.viso() / BANDYMU << " |" << endl;
    }
}
void testuotiKonteinerius() {
    testuotiVienaKonteineri<vector<studentas>>("std::vector");
    testuotiVienaKonteineri<list<studentas>>("std::list");
    cout << "\nLaikai sekundemis. Lenteles galima kopijuoti i README.md.\n";
}
void rankinisSuAdresais() {
    cout << "Kuri konteineri naudoti? 1 - vector, 2 - list: ";
    int k;
    cin >> k;
    cin.ignore();
    if (k == 1) {
        vector<studentas> s;
        ivestiRankiniuSuAdresais(s);
        cout << "\nstd::vector - galutiniai adresai:\n";
        rodytiSuAdresais(s);
    } else {
        list<studentas> s;
        ivestiRankiniuSuAdresais(s);
        cout << "\nstd::list - galutiniai adresai:\n";
        rodytiSuAdresais(s);
    }
}
