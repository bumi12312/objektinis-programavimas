#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct studentas {
    string vardas = "";
    string pavarde = "";
    int n = 0;
    int nd[5];
    int egz = 0;
    float galutinis = 0;
};

int main()
{
    int studSk;
    cout << "Studentu skaičius: ";
    cin >> studSk;
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
            cout << (j+1) << "namu darbo balas: ";
            cin >> s[i].nd[j];
            sum += s[i].nd[j];
        }
        double vidurkis=(double)sum/s[i].n;
        cout << "Egzamino rezultatas: ";
        cin >> s[i].egz;
        s[i].galutinis=0.4*vidurkis+0.6*s[i].egz;
    }
    cout << "\n" << left << setw(10) << "Vardas" << setw(10) << "Pavarde" << "Galutinis\n";
    cout << fixed << setprecision(2);
    for(int i=0;i<studSk;i++) {
        cout << left << setw(10) << s[i].vardas << setw(10) << s[i].pavarde << s[i].galutinis << "\n";
    }
    return 0;
}
