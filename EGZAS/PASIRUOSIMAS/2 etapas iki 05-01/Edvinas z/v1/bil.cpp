#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAXEIL = 100;
const int MAXSTULP = 100;

int nustatytiVietosKaina(int eilesNr) {
    if (eilesNr == 1 || eilesNr == 2) {
        return 100;
    } else if (eilesNr == 3 || eilesNr == 4) {
        return 70;
    } else {
        return 40;
    }
}

void skaiciuotiFinansus(int salis[MAXEIL][MAXSTULP], int eilutes, int stulpeliai, int &bendraSuma, double &vidutineKaina) {
    bendraSuma = 0;
    int parduotiBilietai = 0;

    for (int i = 0; i < eilutes; i++) {
        int kainaEileje = nustatytiVietosKaina(i + 1);

        for (int j = 0; j < stulpeliai; j++) {
            if (salis[i][j] == 1) { 
                bendraSuma += kainaEileje;
                parduotiBilietai++;
            }
        }
    }

    if (parduotiBilietai > 0) {
        vidutineKaina = (double)bendraSuma / parduotiBilietai;
    } else {
        vidutineKaina = 0.0;
    }
}

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int eilutes, stulpeliai;
    int salis[MAXEIL][MAXSTULP];

    fd >> eilutes >> stulpeliai;

    for (int i = 0; i < eilutes; i++) {
        for (int j = 0; j < stulpeliai; j++) {
            fd >> salis[i][j];
        }
    }

    int galutineSuma;
    double vidutineBilietoKaina;

    skaiciuotiFinansus(salis, eilutes, stulpeliai, galutineSuma, vidutineBilietoKaina);

    fr << galutineSuma << " " << fixed << setprecision(2) << vidutineBilietoKaina << "\n";

    fd.close();
    fr.close();

    return 0;
}
