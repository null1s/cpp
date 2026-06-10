#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int n;
    fd >> n;

    int maxTaskai = -1;    
    int laimNr = 1;

   
    for (int i = 1; i <= n; i++) {
        int metsk;
        fd >> metsk;

        int suma = 0;
        bool zaidimasBaigtas = false;

        for (int j = 0; j < metsk; j++) {
            int akutes;
            fd >> akutes;

            if (!zaidimasBaigtas) {
                suma = suma + akutes;

                if (akutes % 2 == 0) {
                    zaidimasBaigtas = true;
                }
            }
        }

        fr << i << " - zaidejas surinko " << suma << " tasku" << endl;

        if (suma > maxTaskai) {
            maxTaskai = suma;
            laimNr = i;
        }
    }

    fr << "zaidima laimejo " << laimNr << " zaidejas, jis surinko " << maxTaskai << " tasku" << endl;

    fd.close();
    fr.close();

    return 0;
}
