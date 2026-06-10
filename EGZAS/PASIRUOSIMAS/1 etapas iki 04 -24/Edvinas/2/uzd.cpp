#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int n;
    fd >> n;

    int isspresta = 0;

    for (int i = 0; i < n; i++) {
        int d;
        fd >> d;

        int mokinioSuma = 0;

        for (int j = 0; j < d; j++) {
            int uzdaviniai;
            fd >> uzdaviniai;
            mokinioSuma = mokinioSuma + uzdaviniai;
        }

        fr << mokinioSuma << endl;

        isspresta = isspresta + mokinioSuma;
    }

    fr << isspresta << endl;

    fd.close();
    fr.close();

    return 0;
}
