#include "ivestis.h"
#include "timer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

void ivestiRankiniu(vector<studentas> &s) {
    int studSk;
    cout << "Studentu skaicius: ";
    cin >> studSk;
    cin.ignore();
    for (int i = 0; i < studSk; i++) {
        studentas stud;
        cout << "\n" << (i+1) << "-as studentas\n";
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
            int balas = stoi(eilute);
            stud.nd.push_back(balas);
        }
        cout << "Egzamino rezultatas: ";
        cin >> stud.egz;
        cin.ignore();
        apskaiciuotiGalutini(stud);
        s.push_back(stud);
    }
}
bool nuskaitytiFaila(const string &failoPav, vector<studentas> &s) {
    ifstream failas(failoPav);
    if (!failas.is_open()) return false;
    string eilute;
    getline(failas, eilute);   // antraste
    while (getline(failas, eilute)) {
        if (eilute.empty()) continue;
        studentas stud;
        istringstream iss(eilute);
        iss >> stud.vardas >> stud.pavarde;
        int balas;
        while (iss >> balas) {
            stud.nd.push_back(balas);
        }
        if (!stud.nd.empty()) {
            stud.egz = stud.nd.back();
            stud.nd.pop_back();
        }
        apskaiciuotiGalutini(stud);
        s.push_back(stud);
    }
    failas.close();
    return true;
}
void nuskaitytiIsFailo(vector<studentas> &s) {
    string failoPav;
    cout << "Iveskite failo pavadinima: ";
    cin >> failoPav;
    cin.ignore();
    Timer t;
    if (!nuskaitytiFaila(failoPav, s)) {
        cout << "Nepavyko atidaryti failo\n";
        return;
    }
    cout << "Duomenys is failo nuskaityti (" << s.size() << " studentu) per "
         << t.elapsed() << " s.\n";
}
void generuotiAtsitiktinai(vector<studentas> &s) {
    int studSk;
    cout << "Studentu skaicius: ";
    cin >> studSk;
    cin.ignore();
    for (int i = 0; i < studSk; i++) {
        studentas stud;
        cout << "\n" << (i+1) << "-as studentas\n";
        cout << "Vardas: ";
        cin >> stud.vardas;
        cout << "Pavarde: ";
        cin >> stud.pavarde;
        cin.ignore();
        int nDarbu = rand() % 5 + 3;
        for (int j = 0; j < nDarbu; j++) {
            stud.nd.push_back(rand() % 10 + 1);
        }
        stud.egz = rand() % 10 + 1;
        cout << "Sugeneruoti namu darbu balai: ";
        for (int balas : stud.nd) cout << balas << " ";
        cout << "\nSugeneruotas egzamino balas: " << stud.egz << "\n";
        apskaiciuotiGalutini(stud);
        s.push_back(stud);
    }
}
