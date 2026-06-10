#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
bool Koduoteje(int sk) {
    if ((sk >= 32 && sk <= 33) || 
        sk == 44 || 
        sk == 46 || 
        (sk >= 48 && sk <= 57) || 
        sk == 63 || 
        (sk >= 65 && sk <= 90) || 
        (sk >= 97 && sk <= 122)) {
        return true;
    }
    return false;
}

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    string eilute;
    while (getline(fd, eilute)) {
        if (eilute.empty()) continue;

        stringstream ss(eilute);
        int skaicius;
        bool visiTeisingi = true;

        while (ss >> skaicius) {
            if (!Koduoteje(skaicius)) {
                visiTeisingi = false; 
                break;
            }
        }

        if (visiTeisingi) {
            fr << "Teisingai" << endl;
        } else {
            fr << "Neteisingas simbolis" << endl;
        }
    }

    fd.close();
    fr.close();
    return 0;
}
