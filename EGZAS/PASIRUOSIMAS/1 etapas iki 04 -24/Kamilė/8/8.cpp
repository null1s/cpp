#include <fstream>
using namespace std;
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int n;
    fd >> n;
    int maxTaskai = 0;
    int laimetojas = 1;
    for (int i = 1; i <= n; i++) {
        int kiek;
        fd >> kiek;
        int suma = 0;
        for (int j = 0; j < kiek; j++) {
            int x;
            fd >> x;
            suma += x;
            if (x % 2 == 0) {
                break; 
            }
        }
        fr << i << " - Zaidejas surinko " << suma << " tasku" << endl;

        if (suma > maxTaskai) {
            maxTaskai = suma;
            laimetojas = i;
        }
    }
    fr << "Zaidima laimejo " << laimetojas 
       << " zaidejas, jis surinko " << maxTaskai << " tasku" << endl;
    fd.close();
    fr.close();
    return 0;
}
