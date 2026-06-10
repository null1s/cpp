#include <iostream>
#include <fstream>
using namespace std;
void atvykimo_laikas(int val, int min, int atstumas, int greitis, int &res_val, int &res_min) {
    int laikas_min = (atstumas * 60) / greitis;
    res_val = val + laikas_min / 60;
    res_min = min + laikas_min % 60;
    if (res_min >= 60) {
        res_val += res_min / 60;
        res_min = res_min % 60;
    }
    res_val = res_val % 24;
}
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int val, min;
    int n;
    fd >> val >> min;
    fd >> n;
    int atstumas, greitis;
    for (int i = 1; i <= n; i++) {
        fd >> atstumas >> greitis;
        int nauj_val, nauj_min;
        atvykimo_laikas(val, min, atstumas, greitis, nauj_val, nauj_min);
        fr << i << " " << nauj_val << " " << nauj_min << endl;
        val = nauj_val;
        min = nauj_min;
    }
    fd.close();
    fr.close();

    return 0;
}
