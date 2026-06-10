#include <iostream>
#include <fstream>

using namespace std;

void Laikas(double s, double v, int &bendMinuciu) {
    double etapoLaikasMin = (s / v) * 60.0;
    
    bendMinuciu += (int)(etapoLaikasMin + 0.5);
}

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int val, min;
    fd >> val >> min; 

    int n;
    fd >> n; 

    int bendMinuciu = val * 60 + min;

    for (int i = 1; i <= n; i++) {
        double s, v;
        fd >> s >> v; 

       Laikas(s, v, bendMinuciu);

        int Valandos = (bendMinuciu / 60) % 24; 
        int Minutes = bendMinuciu % 60;

        fr << i << " " << Valandos << " " << Minutes << endl;
    }

    fd.close();
    fr.close();
    return 0;
}
