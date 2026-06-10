#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int n;
    fd >> n;

    int pjaustyklesSum = 0;
    int virduliaiSum = 0;
    int mikseriaiSum = 0;
    int plaktuvesSum = 0;

    for (int i = 0; i < n; i++) {
        int gn, gs;
        fd >> gn >> gs;

        int eilutesSuma = 0;
        for (int j = 0; j < gs; j++) {
            int savikaina;
            fd >> savikaina;
            eilutesSuma = eilutesSuma + savikaina;
        }

        if (gn == 1) {
            pjaustyklesSum = pjaustyklesSum + eilutesSuma;
        } else if (gn == 2) {
            virduliaiSum = virduliaiSum + eilutesSuma;
        } else if (gn == 3) {
            mikseriaiSum = mikseriaiSum + eilutesSuma;
        } else if (gn == 4) {
            plaktuvesSum = plaktuvesSum + eilutesSuma;
        }
    }

    fr << "Pjaustykliu: " << pjaustyklesSum << " Eur" << endl;
    fr << "Virduliu: " << virduliaiSum << " Eur" << endl;
    fr << "Mikseriu: " << mikseriaiSum << " Eur" << endl;
    fr << "Plaktuviu: " << plaktuvesSum << " Eur" << endl;


    int maxSuma = pjaustyklesSum;
    int maxGaminys = 1;

    if (virduliaiSum > maxSuma) {
        maxSuma = virduliaiSum;
        maxGaminys = 2;
    }
    if (mikseriaiSum > maxSuma) {
        maxSuma = mikseriaiSum;
        maxGaminys = 3;
    }
    if (plaktuvesSum > maxSuma) {
        maxSuma = plaktuvesSum;
        maxGaminys = 4;
    }

    if (maxGaminys == 1) {
        fr << "Pjaustykliu pagaminta didþiausiai sumai" << endl;
    } else if (maxGaminys == 2) {
        fr << "Virduliu pagaminta didþiausiai sumai" << endl;
    } else if (maxGaminys == 3) {
        fr << "Mikseriu pagaminta didþiausiai sumai" << endl;
    } else if (maxGaminys == 4) {
        fr << "Plaktuviu pagaminta didþiausiai sumai" << endl;
    }

    fd.close();
    fr.close();

    return 0;
}
