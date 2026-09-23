#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct studentas {
    string vardas = "";
    string pavarde = "";
    int n = 0;
    int nd[5];
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
    studentas s[100];
    for(int i=0;i<studSk;i++) {
        cout << "\n" << (i+1) << "-as studentas\n";
        cout << "Vardas: ";
        cin >> s[i].vardas;
        cout << "Pavarde: ";
        cin >> s[i].pavarde;
        cout << "Namu darbu kiekis: ";
        cin >> s[i].n;
        int sum=0;
        for(int j=0;j<s[i].n;j++) {
            cout << (j+1) << " namu darbo balas: ";
            cin >> s[i].nd[j];
            sum += s[i].nd[j];
        }
        double vidurkis=(double)sum/s[i].n;
        int nd2[5];
        for(int j=0;j<s[i].n;j++) {
            nd2[j]=s[i].nd[j];
        }
        sort(nd2,nd2+s[i].n);
        float mediana;
        if(s[i].n%2==1) {
            mediana=nd2[s[i].n/2];
        } else {
            mediana=(nd2[s[i].n/2-1] + nd2[s[i].n/2]) /2;
        }
        cout << "Egzamino rezultatas: ";
        cin >> s[i].egz;
        s[i].galutinisVid=0.4*vidurkis+0.6*s[i].egz;
        s[i].galutinisMed=0.4*mediana+0.6*s[i].egz;
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
