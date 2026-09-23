#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct studentas {
    string vardas = "";
    string pavarde = "";
    vector<int> nd;
    int egz = 0;
    float galutinisVid = 0;
    float galutinisMed = 0;
};

int main()
{
    int studSk;
    cout << "Studentu skaičius: ";
    cin >> studSk;
    cout << "Pasirinkite ką naudoti galutinio balo skaičiavimui?\n";
    cout << "1 - Vidurkis\n";
    cout << "2 - Mediana\n";
    cout << "3 - Abu\n";
    int pasirinkimas;
    cout << "Pasirinkimas: ";
    cin >> pasirinkimas;
    cin.ignore();
    
    vector<studentas> s(studSk);
    for(int i=0;i<studSk;i++) {
        cout << "\n" << (i+1) << "-as studentas\n";
        cout << "Vardas: ";
        cin >> s[i].vardas;
        cout << "Pavarde: ";
        cin >> s[i].pavarde;
        cin.ignore();
        cout << "Namu darbu balai (palikti tuscia, kad baigit):\n";
        int sum = 0;
        while (true) {
            string eilute;
            getline(cin, eilute);
            if (eilute.empty()) {
                break;
            }
            int balas = stoi(eilute);
            s[i].nd.push_back(balas);
            sum += balas;
        }
        double vidurkis = (double)sum / s[i].nd.size();
        vector<int> nd2 = s[i].nd;
        sort(nd2.begin(), nd2.end());
        int n = nd2.size();
        float mediana;
        if (n % 2 == 1) {
            mediana = nd2[n/2];
        } else {
            mediana = (nd2[n/2 - 1] + nd2[n/2]) / 2.0;
        }
        cout << "Egzamino rezultatas: ";
        cin >> s[i].egz;
        cin.ignore();
        s[i].galutinisVid = 0.4*vidurkis + 0.6*s[i].egz;
        s[i].galutinisMed = 0.4*mediana + 0.6*s[i].egz;
    }
    cout << "\n" << left << setw(10) << "Vardas" << setw(10) << "Pavarde";
    if (pasirinkimas == 1) {
        cout << "galutinis (Vid.)";
    } else if (pasirinkimas == 2) {
        cout << "Galutinis (Med.)";
    } else {
        cout << "Galutinis (Vid.)/ Galutinis (Med.)";
    }
    cout << "\n";
    cout << "--------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    for(int i=0;i<studSk;i++) {
        cout << left << setw(10) << s[i].vardas << setw(10) << s[i].pavarde;
        if(pasirinkimas == 1) {
            cout << s[i].galutinisVid;
        } else if (pasirinkimas == 2) {
            cout << s[i].galutinisMed;
        } else {
            cout << left << setw(20) << s[i].galutinisVid << s[i].galutinisMed;
        }
        cout << "\n";
    }
    return 0;
}
