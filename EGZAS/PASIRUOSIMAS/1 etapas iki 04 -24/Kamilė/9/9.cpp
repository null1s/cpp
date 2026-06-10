#include <iostream>
#include <fstream>
using namespace std;
int kiekDalikliu(int n) {
    int kiek = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            kiek++;
        }
    }
    return kiek;
}
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int a, b;
    fd >> a >> b;
    int maxKiek = 0;
    int skaicius = a;
    for (int i = a; i <= b; i++) {
        int k = kiekDalikliu(i);
        if (k > maxKiek) {
            maxKiek = k;
            skaicius = i;
        }
    }
    fr << "Skaicius " << skaicius << " turi daugiausia dalikliu " << maxKiek << endl;
    for (int i = 1; i <= skaicius; i++) {
        if (skaicius % i == 0) {
            fr << i << " ";
        }
    }
    fd.close();
    fr.close();
    return 0;
}
