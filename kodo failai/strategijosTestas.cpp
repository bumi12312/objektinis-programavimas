#include "strategijosTestas.h"
#include "strategijos.h"
#include "konteineriai.h"
#include "timer.h"
#include <climits>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<studentas> Vek;
typedef list<studentas> Sar;

const int DYDZIAI[] = {1000, 10000, 100000, 1000000, 10000000};
const int BANDYMU = 3;
const int MAX_NAIVUS_VEKTORIUS = 100000;

template <typename C>
struct Strategija {
    string pavadinimas;
    function<void(C &, C &, C &)> vykdyti;
    int maxIrasu;
};

template <typename C>
struct Rezultatai {
    vector<vector<double>> laikai;
    vector<vector<size_t>> objektai;
};

string skaicius(double v, int tikslumas) {
    ostringstream ss;
    ss << fixed << setprecision(tikslumas) << v;
    return ss.str();
}

void rodytiLentele(const string &pavadinimas, const vector<string> &antrastes,
                   const vector<vector<string>> &eilutes) {
    size_t n = antrastes.size();
    vector<size_t> plotis(n);
    for (size_t i = 0; i < n; i++) plotis[i] = antrastes[i].size();
    for (const auto &e : eilutes)
        for (size_t i = 0; i < n && i < e.size(); i++) plotis[i] = max(plotis[i], e[i].size());

    size_t viso = 3 * (n - 1);
    for (size_t i = 0; i < n; i++) viso += plotis[i];
    string dviguba(viso, '='), vienguba(viso, '-');

    auto eilute = [&](const vector<string> &e) {
        for (size_t i = 0; i < n; i++) {
            cout << left << setw(plotis[i]) << (i < e.size() ? e[i] : "");
            if (i + 1 < n) cout << " | ";
        }
        cout << "\n";
    };

    cout << "\n" << dviguba << "\n" << pavadinimas << "\n" << dviguba << "\n";
    eilute(antrastes);
    cout << dviguba << "\n";
    for (const auto &e : eilutes) {
        eilute(e);
        cout << vienguba << "\n";
    }
    cout << flush;
}

template <typename C>
void matuotiDydi(const C &baze, int n, const vector<Strategija<C>> &strategijos,
                 Rezultatai<C> &rez) {
    size_t tikimasVargsiuku = count_if(baze.begin(), baze.end(), yraVargsiukas);
    vector<double> laikai;
    vector<size_t> objektai;
    for (const auto &st : strategijos) {
        if (n > st.maxIrasu) {
            laikai.push_back(-1);
            objektai.push_back(0);
            continue;
        }
        double suma = 0;
        size_t obj = 0;
        for (int b = 0; b < BANDYMU; b++) {
            C s = baze;               // kopijavimas nematuojamas
            C vargsiukai, kietiakiai;
            Timer t;
            st.vykdyti(s, vargsiukai, kietiakiai);
            suma += t.elapsed();
            obj = s.size() + vargsiukai.size() + kietiakiai.size();
            if (vargsiukai.size() != tikimasVargsiuku)
                cout << "KLAIDA: strategija '" << st.pavadinimas << "' blogai padalino!\n";
        }
        laikai.push_back(suma / BANDYMU);
        objektai.push_back(obj);
    }
    rez.laikai.push_back(laikai);
    rez.objektai.push_back(objektai);
}

template <typename C>
void spausdintiLaikus(const string &pavadinimas, const vector<Strategija<C>> &strategijos,
                      const Rezultatai<C> &rez) {
    vector<string> antrastes;
    antrastes.push_back("Irasu sk.");
    for (const auto &st : strategijos) antrastes.push_back(st.pavadinimas);

    vector<vector<string>> eilutes;
    for (size_t i = 0; i < rez.laikai.size(); i++) {
        vector<string> e;
        e.push_back(to_string(DYDZIAI[i]));
        for (double l : rez.laikai[i]) e.push_back(l < 0 ? "praleista" : skaicius(l, 6));
        eilutes.push_back(e);
    }
    rodytiLentele(pavadinimas + " - dalijimo laikas (s, " + to_string(BANDYMU) +
                  " bandymu vidurkis)", antrastes, eilutes);
}

template <typename C>
void spausdintiAtminti(const string &pavadinimas, size_t baitaiVienam, const Rezultatai<C> &rez) {
    vector<string> antrastes = {"Irasu sk.", "1 strat. objektu", "2/3 strat. objektu",
                                "1 strat. MB", "2/3 strat. MB", "Kartu daugiau (1 strat.)"};
    vector<vector<string>> eilutes;
    for (size_t i = 0; i < rez.objektai.size(); i++) {
        size_t o1 = rez.objektai[i].front();
        size_t o3 = rez.objektai[i].back();
        vector<string> e;
        e.push_back(to_string(DYDZIAI[i]));
        e.push_back(to_string(o1));
        e.push_back(to_string(o3));
        e.push_back(skaicius(o1 * baitaiVienam / 1048576.0, 1));
        e.push_back(skaicius(o3 * baitaiVienam / 1048576.0, 1));
        e.push_back(skaicius((double)o1 / o3, 2));
        eilutes.push_back(e);
    }
    rodytiLentele(pavadinimas + " - atmintis po dalijimo (apytiksl.)", antrastes, eilutes);
}

void palygintiStrategijas() {
    vector<Strategija<Vek>> vekStr = {
        {"1 strat. (kopijavimas)",          dalintiS1<Vek>,  INT_MAX},
        {"2 strat. (erase)",                dalintiS2<Vek>,  MAX_NAIVUS_VEKTORIUS},
        {"3a copy_if+remove_if",            dalintiVekS3a,   INT_MAX},
        {"3b partition",                    dalintiVekS3b,   INT_MAX},
        {"3c stable_partition",             dalintiVekS3c,   INT_MAX}
    };
    vector<Strategija<Sar>> sarStr = {
        {"1 strat. (kopijavimas)",          dalintiS1<Sar>,  INT_MAX},
        {"2 strat. (erase)",                dalintiS2<Sar>,  INT_MAX},
        {"3 strat. (splice)",               dalintiListS3,   INT_MAX}
    };

    Rezultatai<Vek> vekRez;
    Rezultatai<Sar> sarRez;

    for (int n : DYDZIAI) {
        Vek baze;
        if (!skaitytiKonteineri("studentai" + to_string(n) + ".txt", baze)) {
            cout << "Failas studentai" << n << ".txt nerastas - pirma pasirinkite meniu 5.\n";
            break;
        }
        Sar bazeList(baze.begin(), baze.end());
        cout << "Matuojama: " << n << " irasu..." << endl;
        matuotiDydi(baze, n, vekStr, vekRez);
        matuotiDydi(bazeList, n, sarStr, sarRez);
    }

    spausdintiLaikus("std::vector", vekStr, vekRez);
    spausdintiLaikus("std::list", sarStr, sarRez);
    spausdintiAtminti("std::vector", sizeof(studentas) + 5 * sizeof(int), vekRez);
    spausdintiAtminti("std::list", sizeof(studentas) + 5 * sizeof(int) + 2 * sizeof(void *), sarRez);
    cout << "\nLaikai sekundemis.\n";
}