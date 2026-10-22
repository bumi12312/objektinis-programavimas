#include "analize.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "studentas.h"
#include "ivestis.h"
#include "isvestis.h"
#include "generavimas.h"
#include "kategorijos.h"

using namespace std;

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
        cout << "5 - Sugeneruoti 5 studentu sarasu failus\n";
        cout << "6 - Padalinti studentus i kategorijas\n";
        cout << "7 - Spartos analize\n";
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
            case 5:
                generuotiVisusFailus();
                break;
            case 6:
                kategorijos(s);
                break;
            case 7:
                spartosAnalize();
                break;
            case 0:
                cout << "Darbas baigtas.\n";
                break;
            default:
                cout << "Bandykite dar karta.\n";
        }
    } while (pasirink != 0);
    return 0;
}
