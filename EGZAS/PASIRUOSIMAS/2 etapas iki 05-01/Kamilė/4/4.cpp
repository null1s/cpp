#include <fstream>
using namespace std;
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int x;
    bool gerai = true;

    while (fd >> x) {
        if (!((x >= 32 && x <= 57) || 
              (x >= 63 && x <= 90) || 
              (x >= 97 && x <= 122))) {
            
            fr << "Neteisingas simbolis" << endl;
            gerai = false;
        }
    }
    if (gerai) {
        fr << "Teisingai";
    }
    return 0;
}
