#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    string eilute;
    int a, b;
    char kabl; 
    getline(fd, eilute);   
    fd >> a >> kabl >> b;  
    fr << "Skaicius | Dalijasi is:" << endl;
    for (int i = a; i <= b; i++) {
        int kiek = 0;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                kiek++;
            }
		}
        fr << i << " " << kiek << endl;
    }
    fd.close();
    fr.close();

    return 0;
}
