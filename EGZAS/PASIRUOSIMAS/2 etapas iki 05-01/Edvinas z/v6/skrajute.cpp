#include <iostream>
#include <fstream>
using namespace std;
void skaicSavaite(int pirm, int antr, int trec, int &suma, int &virsijo, int &nepasieke) {
    suma = pirm + antr + trec;
    virsijo = 0;
    nepasieke = 0;

    if (pirm > 5) virsijo++;
    else if (pirm < 5) nepasieke++;

    if (antr > 6) virsijo++;
    else if (antr < 6) nepasieke++;

    if (trec > 4) virsijo++;
    else if (trec < 4) nepasieke++;
}
void isvestiSavaite(ofstream &fr, int suma, int virsijo, int nepasieke) {
    fr << suma << " " << virsijo << " " << nepasieke << endl;
}
int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int n;
    fd >> n; 

    int bendraSuma = 0;
    int bendraiVirsijo = 0;
    int bendraiNepasieke = 0;

    for (int i = 0; i < n; i++) {
        int p, a, t;
        fd >> p >> a >> t; 

        int savaitesSuma, savaitesVirsijo, savaitesNepasieke;

        skaicSavaite(p, a, t, savaitesSuma, savaitesVirsijo, savaitesNepasieke);

        isvestiSavaite(fr, savaitesSuma, savaitesVirsijo, savaitesNepasieke);

        bendraSuma += savaitesSuma;
        bendraiVirsijo += savaitesVirsijo;
        bendraiNepasieke += savaitesNepasieke;
    }

    fr << bendraSuma << " " << bendraiVirsijo << " " << bendraiNepasieke << endl;

    fd.close();
    fr.close();

    return 0;
}
