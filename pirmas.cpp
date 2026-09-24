#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

struct studentas {
    string vardas = "";
    string pavarde = "";
    vector<int> nd;
    int egz = 0;
    float galutinisVid = 0;
    float galutinisMed = 0;
};
void apskaiciuotiGalutini(studentas &s) {
    int sum = 0;
    for (int balas : s.nd) sum += balas;
    double vidurkis = (double)sum / s.nd.size();    
    vector<int> nd2 = s.nd;
    sort(nd2.begin(), nd2.end());
    int n = nd2.size();
    float mediana;
    if (n % 2 == 1) {
        mediana = nd2[n/2];
    } else {
        mediana = (nd2[n/2 - 1] + nd2[n/2]) / 2.0;
    }
    s.galutinisVid = 0.4*vidurkis + 0.6*s.egz;
    s.galutinisMed = 0.4*mediana + 0.6*s.egz;
}
void ivestiRankiniu(vector<studentas> &s) {
    int studSk;
    cout << "Studentu skaičius: ";
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
        cout << "Namu darbu balai (palikti tuscia, kad baigit):\n";
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
void nuskaitytiIsFailo(vector<studentas> &s) {
    string failoPav;
    cout << "Iveskite failo pavadinima: ";
    cin >> failoPav;
    cin.ignore();
    ifstream failas(failoPav);
    if (!failas.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return;
    }
    string eilute;
    getline(failas, eilute);
    while (getline(failas, eilute)) {
        if (eilute.empty()) continue;
        studentas stud;
        istringstream iss(eilute);
        iss >> stud.pavarde >> stud.vardas;
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
    cout << "Duomenys is failo sekmingai nuskaityti (" << s.size() << " studentu).\n";
}
void generuotiAtsitiktinai(vector<studentas> &s) {
    int studSk;
    cout << "Studentu skaičius: ";
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
void rodytiRezultatus(const vector<studentas> &s, int pasirinkimas) {
    if (s.empty()) {
        cout << "Duomenu nera - ivesk arba sugeneruok duomenis.\n";
        return;
    }
    vector<studentas> rusiavimas = s;
    sort(rusiavimas.begin(),rusiavimas.end(),
        [](const studentas &a, const studentas &b) {
            return a.pavarde < b.pavarde;
        });
    cout << "\n" << left << setw(10) << "Vardas" << setw(10) << "Pavarde";
    if (pasirinkimas == 1) {
        cout << "Galutinis (Vid.)";
    } else if (pasirinkimas == 2) {
        cout << "Galutinis (Med.)";
    } else {
        cout << "Galutinis (Vid.)/ Galutinis (Med.)";
    }
    cout << "\n";
    cout << "--------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    for (const auto &stud : s) {
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
int main()
{
    srand((unsigned)time(0));
    vector<studentas> s;
    int pasirink;
    do {
        cout << "\n----- MENIU -----\n";
        cout << "1 - Ivesti studentu duomenis ranka\n";
        cout << "2 - Generuoti studentu duomenis\n";
        cout << "3 - Duomenu nuskaitymas is failo\n";
        cout << "4 - Rodyti rezultatus\n";
        cout << "0 - Baigti darba\n";
        cout << "Pasirinkimas: ";
        cin >> pasirink;
        switch (pasirink) {
            case 1:
                ivestiRankiniu(s);
                break;
            case 2:
                generuotiAtsitiktinai(s);
                break;
            case 3:
                nuskaitytiIsFailo(s);
                break;
            case 4: {
                cout << "Ka naudoti galutinio balo skaiciavimui?\n";
                cout << "1 - Vidurkis\n2 - Mediana\n3 - Abu\n";
                int pasirinkimas;
                cout << "Pasirinkimas: ";
                cin >> pasirinkimas;
                rodytiRezultatus(s, pasirinkimas);
                break;
            }
            case 0:
                cout << "Darbas baigtas.\n";
                break;
            default:
                cout << "Bandykite dar karta.\n";
        }
    } while (pasirink != 0);
    return 0;
}
