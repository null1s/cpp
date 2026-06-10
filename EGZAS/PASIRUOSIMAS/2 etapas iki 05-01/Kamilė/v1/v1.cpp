#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int kaina(int eile) {
    if (eile == 1 || eile == 2) return 100;
    if (eile == 3 || eile == 4) return 70;
    return 40;
}
void procedura(int sale[100][100], int eil, int viet, int &suma, double &vidurkis) {
    int kiekis = 0;
    suma = 0;
    for (int i = 0; i < eil; i++) {
        for (int j = 0; j < viet; j++) {
            if (sale[i][j] == 1) {
                suma += kaina(i + 1);
                kiekis++;
            }
        }
    }
    if (kiekis > 0)
        vidurkis = (double)suma / kiekis;
    else
        vidurkis = 0;
}
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int eil, viet;
    int sale[100][100];
    while (fd >> eil >> viet) {
        for (int i = 0; i < eil; i++) {
            for (int j = 0; j < viet; j++) {
                fd >> sale[i][j];
            }
        }
        int suma;
        double vidurkis;
        procedura(sale, eil, viet, suma, vidurkis);
        fr << suma << " " << fixed << setprecision(2) << vidurkis << endl;
    }
    fd.close();
    fr.close();
    return 0;
}
