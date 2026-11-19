#include "testas.h"
#include "konteineriai.h"
#include "timer.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>

using namespace std;

const int DYDZIAI[] = {1000, 10000, 100000, 1000000, 10000000};
const int KIEK_DYDZIU = 5;
const int BANDYMU = 3;

struct Laikai {
    bool pavyko = false;
    double nuskaitymas = 0.0;
    double dalinimas = 0.0;
    double rusiavimas = 0.0;
    double isvedimasKietiakiai = 0.0;
    double isvedimasVargsiukai = 0.0;

    double viso() const {
        return nuskaitymas + dalinimas + rusiavimas + isvedimasKietiakiai + isvedimasVargsiukai;
    }
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
    rasytiKonteineri(kietiakiai, "kietiakiai.txt");
    l.isvedimasKietiakiai = t.elapsed();

    t.reset();
    rasytiKonteineri(vargsiukai, "vargsiukai.txt");
    l.isvedimasVargsiukai = t.elapsed();

    return true;
}

template <typename C>
vector<Laikai> rinktiKonteinerioLaikus(const string &pavadinimas) {
    vector<Laikai> rezultatai(KIEK_DYDZIU);
    cout << "Matuojamas " << pavadinimas << " (" << BANDYMU << " bandymu vidurkis)...\n";

    for (int i = 0; i < KIEK_DYDZIU; i++) {
        int n = DYDZIAI[i];
        Laikai suma;
        bool ok = true;

        for (int b = 0; b < BANDYMU; b++) {
            Laikai l;
            if (!matuotiViena<C>(n, l)) {
                ok = false;
                break;
            }
            suma.nuskaitymas += l.nuskaitymas;
            suma.dalinimas += l.dalinimas;
            suma.rusiavimas += l.rusiavimas;
            suma.isvedimasKietiakiai += l.isvedimasKietiakiai;
            suma.isvedimasVargsiukai += l.isvedimasVargsiukai;
        }

        if (ok) {
            rezultatai[i].pavyko = true;
            rezultatai[i].nuskaitymas = suma.nuskaitymas / BANDYMU;
            rezultatai[i].dalinimas = suma.dalinimas / BANDYMU;
            rezultatai[i].rusiavimas = suma.rusiavimas / BANDYMU;
            rezultatai[i].isvedimasKietiakiai = suma.isvedimasKietiakiai / BANDYMU;
            rezultatai[i].isvedimasVargsiukai = suma.isvedimasVargsiukai / BANDYMU;
        }
    }
    return rezultatai;
}

void spausdintiDetaliaAtaskaita(const string &konteinerioPav, const vector<Laikai> &rez) {
    cout << "  " << konteinerioPav << " SPARTOS ANALIZE (DETALUS LAIKAI)\n";
    cout << fixed << setprecision(5);

    for (int i = 0; i < KIEK_DYDZIU; i++) {
        int n = DYDZIAI[i];
        string failas = "studentai" + to_string(n) + ".txt";
        cout << "\n" << n << " irasu spartos analize (" << konteinerioPav << "):\n";
        if (!rez[i].pavyko) {
            cout << "  Failas " << failas << " nerastas (pirma pasirinkite meniu 5).\n";
            continue;
        }
        cout << "  Failo " << failas << " irasu nuskaitymo laikas: " << rez[i].nuskaitymas << " sekundes.\n";
        cout << "  Failo " << failas << " irasu dalinimo i kietiakius ir vargsiukus laikas: " << rez[i].dalinimas << " sekundes.\n";
        cout << "  Failo " << failas << " irasu rusiavimo laikas: " << rez[i].rusiavimas << " sekundes.\n";
        cout << "  Failo " << failas << " irasu kietiakiu irasymo i faila laikas: " << rez[i].isvedimasKietiakiai << " sekundes.\n";
        cout << "  Failo " << failas << " irasu vargsiuku irasymo i faila laikas: " << rez[i].isvedimasVargsiukai << " sekundes.\n";
        cout << "  Viso testo veikimas uztruko: " << rez[i].viso() << " sekundes.\n";
    }
}

void spausdintiPalyginimoLenteles(const vector<Laikai> &vek, const vector<Laikai> &lst) {
    cout << "  VECTOR IR LIST SPARTOS PALYGINIMAS PAGAL OPERACIJAS\n";
    cout << fixed << setprecision(5);

    for (int i = 0; i < KIEK_DYDZIU; i++) {
        int n = DYDZIAI[i];
        cout << "\n* " << n << " irasu vector ir list spartos palyginimas:\n\n";

        if (!vek[i].pavyko || !lst[i].pavyko) {
            cout << "  Failas studentai" << n << ".txt nerastas (pirma pasirinkite meniu 5).\n";
            continue;
        }

        cout << "+--------------------------------+--------------+--------------+\n";
        cout << "| " << left << setw(30) << "Operacija"
             << " | " << right << setw(12) << "Vector (s)"
             << " | " << right << setw(12) << "List (s)" << " |\n";
        cout << "+--------------------------------+--------------+--------------+\n";

        cout << "| " << left << setw(30) << "Nuskaitymas"
             << " | " << right << setw(12) << vek[i].nuskaitymas
             << " | " << right << setw(12) << lst[i].nuskaitymas << " |\n";

        cout << "| " << left << setw(30) << "Dalinimas"
             << " | " << right << setw(12) << vek[i].dalinimas
             << " | " << right << setw(12) << lst[i].dalinimas << " |\n";

        cout << "| " << left << setw(30) << "Rusiavimas"
             << " | " << right << setw(12) << vek[i].rusiavimas
             << " | " << right << setw(12) << lst[i].rusiavimas << " |\n";

        cout << "| " << left << setw(30) << "Isvedimas (kietiakiai)"
             << " | " << right << setw(12) << vek[i].isvedimasKietiakiai
             << " | " << right << setw(12) << lst[i].isvedimasKietiakiai << " |\n";

        cout << "| " << left << setw(30) << "Isvedimas (vargsiukai)"
             << " | " << right << setw(12) << vek[i].isvedimasVargsiukai
             << " | " << right << setw(12) << lst[i].isvedimasVargsiukai << " |\n";

        cout << "+--------------------------------+--------------+--------------+\n";
        cout << "| " << left << setw(30) << "Viso"
             << " | " << right << setw(12) << vek[i].viso()
             << " | " << right << setw(12) << lst[i].viso() << " |\n";
        cout << "+--------------------------------+--------------+--------------+\n";
    }
}

void testuotiKonteinerius() {
    vector<Laikai> vekRez = rinktiKonteinerioLaikus<vector<studentas>>("std::vector");
    vector<Laikai> listRez = rinktiKonteinerioLaikus<list<studentas>>("std::list");

    spausdintiDetaliaAtaskaita("std::vector", vekRez);
    spausdintiDetaliaAtaskaita("std::list", listRez);
    spausdintiPalyginimoLenteles(vekRez, listRez);
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
