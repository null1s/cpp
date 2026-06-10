#include <iostream>
#include <fstream>

using namespace std;

int main() {
   
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int a, b;
    fd >> a >> b;
    int maxDal = 0;          
    int skaiMax = a;        

   
    for (int i = a; i <= b; i++) {
        int dalKiek = 0;
       
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                dalKiek++;
            }
        }

        if (dalKiek > maxDal) {
            maxDal = dalKiek;
            skaiMax = i;
        }
    }

    fr << "Skaicius " << skaiMax << " turi daugiausia dalikliu " << maxDal << endl;

    for (int j = 1; j <= skaiMax; j++) {
        if (skaiMax % j == 0) {
            fr << j << " ";
        }
    }
    fr << endl;

    fd.close();
    fr.close();

    return 0;
}
