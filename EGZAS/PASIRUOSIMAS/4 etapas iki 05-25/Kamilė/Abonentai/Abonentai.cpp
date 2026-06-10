#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX = 100;

string vardas[MAX], pavarde[MAX], miestas[MAX];
string numeris[MAX];
int minutesA[MAX];

string miestaiK[MAX];
double kainos[MAX];

string vardasR[MAX], pavardeR[MAX];
double moketi[MAX];

int n, m, k;

void Skaityti1() {
    ifstream fd("duom1.txt");
    fd >> n;
    for (int i = 0; i < n; i++) {
        fd >> pavarde[i] >> vardas[i] >> numeris[i] >> miestas[i] >> minutesA[i];
    }
    fd.close();
}

void Skaityti2() {
    ifstream fd("duom2.txt");
    fd >> m;
    for (int i = 0; i < m; i++) {
        fd >> miestaiK[i] >> kainos[i];
    }
    fd.close();
}

double RastiKaina(string miestasX) {
    for (int i = 0; i < m; i++) {
        if (miestaiK[i] == miestasX) {
            return kainos[i];
        }
    }
    return 0;
}

void Skaiciuoti() {
    k = 0;
    for (int i = 0; i < n; i++) {
        double suma = minutesA[i] * RastiKaina(miestas[i]);

        int poz = -1;
        for (int j = 0; j < k; j++) {
            if (vardasR[j] == vardas[i] && pavardeR[j] == pavarde[i]) {
                poz = j;
            }
        }

        if (poz == -1) {
            vardasR[k] = vardas[i];
            pavardeR[k] = pavarde[i];
            moketi[k] = suma;
            k++;
        } else {
            moketi[poz] += suma;
        }
    }
}

void Rikiuoti() {
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (pavardeR[i] > pavardeR[j]) {
                swap(pavardeR[i], pavardeR[j]);
                swap(vardasR[i], vardasR[j]);
                swap(moketi[i], moketi[j]);
            }
        }
    }
}

void Rasyti() {
    ofstream fr("rez.txt");
    double suma = 0;

    for (int i = 0; i < k; i++) {
        fr << pavardeR[i] << " " << vardasR[i] << " "
           << fixed << setprecision(2) << moketi[i] << endl;
        suma += moketi[i];
    }

    fr << "Pajamos: " << fixed << setprecision(2) << suma;
    fr.close();
}

int main() {
    Skaityti1();
    Skaityti2();
    Skaiciuoti();
    Rikiuoti();
    Rasyti();
    return 0;
}
