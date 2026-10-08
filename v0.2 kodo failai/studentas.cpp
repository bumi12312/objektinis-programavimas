#include "studentas.h"
#include <algorithm>

using namespace std;

void apskaiciuotiGalutini(studentas &s) {
    if (s.nd.empty()) {
        s.galutinisVid = 0.6 * s.egz;
        s.galutinisMed = 0.6 * s.egz;
        return;
    }
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
