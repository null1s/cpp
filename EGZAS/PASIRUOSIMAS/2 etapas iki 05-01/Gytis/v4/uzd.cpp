#include<iostream>
#include<fstream>
using namespace std;

struct Baras {
    int g1;
    int g2;
    int val;
};

void skaiciavimas(int a, int b, Baras A[], int &k1, int &k2, int &maxPelnas) {
    maxPelnas = 0;
    k1 = 0;
    k2 = 0;

    // Perrankos budu tikriname visus imanomus kiekius
    // Kadangi max laikas 30 val, o min gaminimo laikas 2 val (pavyzdyje), 
    // 50 yra saugus limitas ciklams.
    for (int i = 0; i <= 50; i++) {         // i - I rušies gaminiai
        for (int j = 0; j <= 50; j++) {     // j - II rušies gaminiai
            
            bool telpa = true;
            // Tikriname, ar šis derinys neviršija ne vieno baro laiko
            for (int k = 0; k < 4; k++) {
                if (i * A[k].g1 + j * A[k].g2 > A[k].val) {
                    telpa = false;
                }
            }

            // Jei derinys galimas, skaiciuojame pelna
            if (telpa) {
                int dabartinisPelnas = i * a + j * b;
                if (dabartinisPelnas > maxPelnas) {
                    maxPelnas = dabartinisPelnas;
                    k1 = i;
                    k2 = j;
                }
            }
        }
    }
}

int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");

    int a, b, n = 4;
    fd >> a >> b;

    Baras A[4];
    
    for (int i = 0; i < n; i++) fd >> A[i].val;
    for (int i = 0; i < n; i++) fd >> A[i].g1;
    for (int i = 0; i < n; i++) fd >> A[i].g2;

    int kiekisI, kiekisII, pelnas = 0;
    
    skaiciavimas(a, b, A, kiekisI, kiekisII, pelnas);

    fr << kiekisI << " " << kiekisII << endl;
    fr << "pelnas " << pelnas << " Lt" << endl;

    fd.close();
    fr.close();
    return 0;
}

