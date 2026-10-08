#include "generavimas.h"
#include "timer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void generuotiFaila(int kiekis) {
    Timer t;
    ofstream out("studentai" + to_string(kiekis) + ".txt");
    out << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egz.\n";
    for (int i = 1; i <= kiekis; i++) {
        out << "Vardas" << i << " Pavarde" << i;
        for (int j = 0; j < 6; j++) {
            out << " " << rand() % 10 + 1;
        }
        out << "\n";
    }
    out.close();
    cout << "Sukurtas failas su " << kiekis << " irasu per " << t.elapsed() << " s.\n";
}
void generuotiVisusFailus() {
    generuotiFaila(1000);
    generuotiFaila(10000);
    generuotiFaila(100000);
    generuotiFaila(1000000);
    generuotiFaila(10000000);
}
