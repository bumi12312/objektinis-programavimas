#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct studentas {
    string vardas = "";
    string pavarde = "";
    int n = 0;
    int nd = 0;
    int egz = 0;
    float galutinis = 0;
};

int main()
{
    int studSk;
    cout << "Studentu skaičius: ";
    cin >> studSk;
    Studentas s[100];
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
            suma += s[i].nd[j];
        }
