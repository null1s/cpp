#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

   

    string prefiksas;
    string numeris;  

    while (fd >> prefiksas >> numeris) {
        int suma = 0;

        for (int i = 0; i < numeris.length(); i++) {
            int skaitmuo = numeris[i] - '0';

            if (i % 2 == 0) {
                skaitmuo = skaitmuo * 2;

                if (skaitmuo >= 10) {
                    skaitmuo = (skaitmuo % 10) + (skaitmuo / 10);
                }
            }

            suma = suma + skaitmuo;
        }

        if (suma % 10 == 0) {
            fr << "Teisingas" << endl;
        } else {
            fr << "Neteisingas" << endl;
        }
    }

    fd.close();
    fr.close();

    return 0;
}

