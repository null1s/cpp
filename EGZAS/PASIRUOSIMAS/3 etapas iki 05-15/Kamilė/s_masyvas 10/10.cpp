#include <iostream>
#include <fstream>
using namespace std;

struct Vaistas {
    int tipas;
    int data;
    double kaina;
};

void skaityti(Vaistas A[], int &n) {
    ifstream fd("duom.txt");
    fd >> n;
    for (int i = 0; i < n; i++) {
        fd >> A[i].tipas >> A[i].data >> A[i].kaina;
    }
    fd.close();
}

bool pasibaiges(int data) {
    int siandien = 20160201;
    return data < siandien;
}

void skaiciuoti(Vaistas A[], int n, int &reikia, int &med, double &suma) {
    reikia = 0;
    med = 0;
    suma = 0;

    for (int i = 0; i < n; i++) {
        if (pasibaiges(A[i].data)) {
            reikia++;
            suma += A[i].kaina;
            if (A[i].tipas == 2) {
                med++;
            }
        }
    }
}

void rasyti(int reikia, int med, double suma) {
    ofstream fr("rez.txt");
    fr << "Nupirkti reikes " << med << " medicininiu priemoniu" << endl;
    fr << "Nupirkti reikes " << reikia << " vaistu" << endl;
    fr << "Seima patirs " << suma << " Lt nuostoli" << endl;
    fr.close();
}

int main() {
    Vaistas A[100];
    int n;
    int reikia, med;
    double suma;

    skaityti(A, n);
    skaiciuoti(A, n, reikia, med, suma);
    rasyti(reikia, med, suma);

    return 0;
}
