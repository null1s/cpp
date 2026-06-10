#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int n;
    fd >> n;
    int viso = 0;
    for (int i = 0; i < n; i++) {
        int d;
        fd >> d;
        int suma = 0;
        int x;
        for (int j = 0; j < d; j++) {
            fd >> x;
            suma += x;
        }
        fr << suma << endl;
        viso += suma;
    }
    fr << viso << endl;
    fd.close();
    fr.close();
    
    return 0;
}
