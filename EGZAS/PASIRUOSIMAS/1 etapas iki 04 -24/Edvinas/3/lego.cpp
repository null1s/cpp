#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    double  Sutaupe = 0.00;

    for (int i = 0; i < 6; i++) {
        int n;
        fd >> n;

        for (int j = 0; j < n; j++) {
            double imesta;
            fd >> imesta;
             Sutaupe =  Sutaupe + imesta;
        }
    }

    double robotoKaina;
    fd >> robotoKaina;

    fr << fixed << setprecision(2) <<  Sutaupe << endl;

    if ( Sutaupe >= robotoKaina) {
        fr << "Uzteks" << endl;
    } else {
        fr << "Neuzteks" << endl;
    }

    fd.close();
    fr.close();

    return 0;
}
