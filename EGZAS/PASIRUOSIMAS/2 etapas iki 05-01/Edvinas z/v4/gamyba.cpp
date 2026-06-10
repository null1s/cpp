#include <iostream>
#include <fstream>
using namespace std;
const int BARU_SK = 4;
void Gamyba(int a, int b, int h[], int laikasI[], int laikasII[], int &kiekI, int &kiekII, int &maxPelnas) {
    maxPelnas = -1; 
    kiekI = 0;
    kiekII = 0;

    int maxGalimasI = 100; 

    for (int i = 0; i <= maxGalimasI; i++) {
        for (int j = 0; j <= maxGalimasI; j++) {
           
            bool tinka = true;
            for (int k = 0; k < BARU_SK; k++) {
                int sunaudotasLaikas = i * laikasI[k] + j * laikasII[k];
                if (sunaudotasLaikas > h[k]) {
                    tinka = false; 
                    break;
                }
            }

            if (tinka) {
                int dabartinisPelnas = i * a + j * b;
                if (dabartinisPelnas > maxPelnas) {
                    maxPelnas = dabartinisPelnas;
                    kiekI = i;
                    kiekII = j;
                }
            }
        }
    }
}

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int a, b;
    int h[BARU_SK];
    int laikasI[BARU_SK];
    int laikasII[BARU_SK];

    fd >> a >> b;

    for (int i = 0; i < BARU_SK; i++) {
        fd >> h[i];
    }

    for (int i = 0; i < BARU_SK; i++) {
        fd >> laikasI[i];
    }

    for (int i = 0; i < BARU_SK; i++) {
        fd >> laikasII[i];
    }

    int geriausiasI, geriausiasII, maksimalusPelnas;

    Gamyba(a, b, h, laikasI, laikasII, geriausiasI, geriausiasII, maksimalusPelnas);

    fr << geriausiasI << " " << geriausiasII << "\n";
    fr << "pelnas " << maksimalusPelnas << " Lt\n";

    fd.close();
    fr.close();

    return 0;
}
