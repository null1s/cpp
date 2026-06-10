#include <fstream>
using namespace std;
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int n;
    fd >> n;
    int pjaus = 0;
    int vird = 0;
    int miks = 0;
    int plak = 0;
    for (int i = 0; i < n; i++) {
        int tipas, kiek;
        fd >> tipas >> kiek;
        for (int j = 0; j < kiek; j++) {
            int kaina;
            fd >> kaina;
            if (tipas == 1) pjaus += kaina;
            if (tipas == 2) vird += kaina;
            if (tipas == 3) miks += kaina;
            if (tipas == 4) plak += kaina;
        }
    }
    fr << "Pjaustykliu: " << pjaus << " Eur" << endl;
    fr << "Virduliu: " << vird << " Eur" << endl;
    fr << "Mikseriu: " << miks << " Eur" << endl;
    fr << "Plaktuviu: " << plak << " Eur" << endl;
    int max = pjaus;
    string kas = "Pjaustykliu";
    if (vird > max) { max = vird; kas = "Virduliu"; }
    if (miks > max) { max = miks; kas = "Mikseriu"; }
    if (plak > max) { max = plak; kas = "Plaktuviu"; }
    fr << kas << " pagaminta didziausiai sumai" << endl;
    fd.close();
    fr.close();

    return 0;
}
