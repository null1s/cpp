#include <iostream>
#include <fstream>
using namespace std;

void skaityti(int &n1, int &n2, int &n, int K[]) {
    ifstream fd("duom.txt");
    fd >> n1 >> n2;   
    fd >> n;          

    for (int i = 0; i < n; i++) {
        fd >> K[i];   
    }

    fd.close();
}

void skaiciuoti(int n1, int n2, int n, int K[],
                int &p1=0, int &p2=0, int &skaicius=0, int &paskutinis=0) {


    for (int i = 0; i < n; i++) {
        int kiek = K[i];
        int pirko = 0;

        
        while (kiek >= 2 && n2 > 0) {
            kiek -= 2;
            n2--;
            p2++;
            pirko = 1;
        }

       
        while (kiek >= 1 && n1 > 0) {
            kiek -= 1;
            n1--;
            p1++;
            pirko = 1;
        }

        if (pirko) {
            klientu_skaicius++;
            paskutinis = K[i]; 
        }
    }
}

void israsyti(int p1, int p2, int skaicius, int paskutinis) {
    ofstream fr("rez.txt");
    fr << p1 << " " << p2 << endl;
    fr << skaicius << endl;
    fr << paskutinis << endl;
    fr.close();
}

int main() {
    int n1, n2, n;
    int K[100];

    int p1, p2, skaicius, paskutinis;

    skaityti(n1, n2, n, K);
    skaiciuoti(n1, n2, n, K, p1, p2,skaicius, paskutinis);
    israsyti(p1, p2, skaicius, paskutinis);

    return 0;
}
