#include <iostream>
#include <fstream>
using namespace std;

void skaityti(int A[][4], int &n) {
    ifstream fd("duom.txt");
    fd >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            fd >> A[i][j];
        }
    }
    fd.close();
}

int komplektai(int A[][4], int n, int liko[]) {
    int suma[4] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            suma[j] += A[i][j];
        }
    }

    int k = suma[0];
    for (int i = 1; i < 4; i++) {
        if (suma[i] < k) k = suma[i];
    }

    for (int i = 0; i < 4; i++) {
        liko[i] = suma[i] - k;
    }

    return k;
}

void rasyti(int k, int liko[]) {
    ofstream fr("rez.txt");

    fr << k << endl;
    for (int i = 0; i < 4; i++) {
        fr << liko[i] << endl;
    }

    fr.close();
}

int main() {
    int A[15][4];
    int n;
    int liko[4];

    skaityti(A, n);
    int k = komplektai(A, n, liko);
    rasyti(k, liko);

    return 0;
}
