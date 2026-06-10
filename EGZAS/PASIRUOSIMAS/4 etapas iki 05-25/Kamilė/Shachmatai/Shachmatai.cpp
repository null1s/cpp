#include <fstream>
#include <string>
using namespace std;

int p[1000], b[1000], z[1000], r[1000], v[1000], k[1000];
int kiekP = 0, kiekB = 0, kiekZ = 0, kiekR = 0, kiekV = 0, kiekK = 0;

void Duomenys() {
    ifstream fd("duom.txt");
    int n;
    fd >> n;
    char x;
    for (int i = 0; i < n; i++) {
        fd >> x;
        if (x == 'p') kiekP++;
        if (x == 'b') kiekB++;
        if (x == 'z') kiekZ++;
        if (x == 'r') kiekR++;
        if (x == 'v') kiekV++;
        if (x == 'k') kiekK++;
    }
    fd.close();
}

void Spausdinti(ofstream &fr) {
    fr << "p " << kiekP << endl;
    fr << "b " << kiekB << endl;
    fr << "z " << kiekZ << endl;
    fr << "r " << kiekR << endl;
    fr << "v " << kiekV << endl;
    fr << "k " << kiekK << endl;
}

int Komplektai() {
    int min = kiekP / 16;
    if (kiekB / 4 < min) min = kiekB / 4;
    if (kiekZ / 4 < min) min = kiekZ / 4;
    if (kiekR / 4 < min) min = kiekR / 4;
    if (kiekV / 2 < min) min = kiekV / 2;
    if (kiekK / 2 < min) min = kiekK / 2;
    return min;
}

void Liko(int komp, ofstream &fr) {
    fr << komp << endl;

    fr << "p " << kiekP - komp * 16 << endl;
    fr << "b " << kiekB - komp * 4 << endl;
    fr << "z " << kiekZ - komp * 4 << endl;
    fr << "r " << kiekR - komp * 4 << endl;
    fr << "v " << kiekV - komp * 2 << endl;
    fr << "k " << kiekK - komp * 2 << endl;
}

int main() {
    Duomenys();

    ofstream fr("rez.txt");

    Spausdinti(fr);

    int komp = Komplektai();

    Liko(komp, fr);

    fr.close();

    return 0;
}
