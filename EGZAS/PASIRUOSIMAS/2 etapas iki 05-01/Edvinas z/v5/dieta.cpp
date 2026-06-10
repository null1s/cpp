#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void skaicKomponentus(ofstream &fr, double grikiai, double a100, double b100, double r100) {
    double angliavandeniai = (grikiai / 100.0) * a100;
    double baltymai = (grikiai / 100.0) * b100;
    double riebalai = (grikiai / 100.0) * r100;

    fr << fixed << setprecision(1) << angliavandeniai << " " << baltymai << " " << riebalai << endl;
}

bool arUztenkaKaloriju(double grikiai) {
    double kalorijos = grikiai * 3.49;
    if (kalorijos >= 1800.0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int n;
    fd >> n; 

    double a100, b100, r100;
    fd >> a100 >> b100 >> r100; 

    int dienosKalorijos = 0;

    for (int i = 0; i < n; i++) {
        double suvalgytaGrikis;
        fd >> suvalgytaGrikis; 

        skaicKomponentus(fr, suvalgytaGrikis, a100, b100, r100);

        if (arUztenkaKaloriju(suvalgytaGrikis)) {
            dienosKalorijos++;
        }
    }

    fr << "Vaida suvartojo reikiama kaloriju kieki " << dienosKalorijos << " dienas" << endl;

    fd.close();
    fr.close();

    return 0;
}
