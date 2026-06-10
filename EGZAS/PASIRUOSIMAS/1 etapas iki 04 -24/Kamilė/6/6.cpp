#include <fstream>
using namespace std;
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    string s;
    while (fd >> s) {
        if (s == "Nr.") continue;
        int suma = 0;
        int dauginti = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int sk = s[i] - '0';
            if (dauginti == 1) {
                sk = sk * 2;
                if (sk > 9) {
                    sk = sk - 9; 
                }
            }
            suma += sk;
            if (dauginti == 0)
                dauginti = 1;
            else
                dauginti = 0;
        }
        if (suma % 10 == 0)
            fr << "Teisingas" << endl;
        else
            fr << "Neteisingas" << endl;
    }
    fd.close();
    fr.close();

    return 0;
}
