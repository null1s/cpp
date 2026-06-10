#include <fstream>
using namespace std;

int vaikai[50];

int rastiPozicija(int n, int k) {
    int poz = 0;
    while (n > 1) {
        poz = (poz + k) % n;
        n--;
    }
    return poz;
}

void Duomenys(int &n, int &k, int &nr) {
    ifstream fd("duom.txt");
    fd >> n >> k >> nr;
    for (int i = 0; i < n; i++) {
        fd >> vaikai[i];
    }
    fd.close();
}

void Rasyti(int n, int poz, int nr) {
    ofstream fr("rez.txt");

    for (int i = 0; i < n + 1; i++) {
        if (i == poz) {
            fr << nr << " ";
        }
        if (i < n) {
            fr << vaikai[i] << " ";
        }
    }

    fr.close();
}

int main() {
    int n, k, nr;

    Duomenys(n, k, nr);

    int poz = rastiPozicija(n + 1, k);

    Rasyti(n, poz, nr);

    return 0;
}
