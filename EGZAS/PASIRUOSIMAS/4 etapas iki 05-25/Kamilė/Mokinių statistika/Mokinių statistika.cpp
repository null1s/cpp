#include <fstream>
#include <string>
using namespace std;

void skaityti(string vardai[], string pavardes[], int &n) {
    ifstream fd("duom.txt");
    fd >> n;
    fd.ignore();
    for (int i = 0; i < n; i++) {
        fd >> pavardes[i] >> vardai[i];
    }
    fd.close();
}

bool arMergaite(string vardas) {
    int ilgis = vardas.length();
    if (vardas[ilgis - 1] == 'a' || vardas[ilgis - 1] == 'e')
        return true;
    return false;
}

void rasyti(string vardai[], string pavardes[], int n) {
    ofstream fr("rez.txt");
    int kiek = 0;

    for (int i = 0; i < n; i++) {
        if (arMergaite(vardai[i])) {
            kiek++;
        }
    }

    fr << kiek << endl;

    for (int i = 0; i < n; i++) {
        if (arMergaite(vardai[i])) {
            fr << pavardes[i] << " " << vardai[i] << endl;
        }
    }

    fr.close();
}

int main() {
    string vardai[100], pavardes[100];
    int n;

    skaityti(vardai, pavardes, n);
    rasyti(vardai, pavardes, n);

    return 0;
}
