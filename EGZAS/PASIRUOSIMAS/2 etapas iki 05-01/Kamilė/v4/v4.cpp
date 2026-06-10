#include <iostream>
#include <fstream>
using namespace std;
void SK(int a, int b, int H[4], int A[4], int B[4],
        int &K1, int &K2, int &P) {

    K1 = 0;
    K2 = 0;
    P = 0;

    for (int i = 0; i < 4; i++) {
        if (A[i] > 0 && B[i] == 0) {
            int kiek = H[i] / A[i];
            K1 += kiek;
            P += kiek * a;
        }
        else if (A[i] == 0 && B[i] > 0) {
            int kiek = H[i] / B[i];
            K2 += kiek;
            P += kiek * b;
        }
        else if (A[i] > 0 && B[i] > 0) {

            int kiek1 = H[i] / A[i];
            int kiek2 = H[i] / B[i];

            int pelnas1 = kiek1 * a;
            int pelnas2 = kiek2 * b;

            if (pelnas1 > pelnas2) {
                K1 += kiek1;
                P += pelnas1;
            } else {
                K2 += kiek2;
                P += pelnas2;
            }
        }
    }
}

int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");

    int a, b;
    int H[4], A[4], B[4];
    fd >> a >> b;
    for (int i = 0; i < 4; i++) fd >> H[i];
    for (int i = 0; i < 4; i++) fd >> A[i];
    for (int i = 0; i < 4; i++) fd >> B[i];
    int K1, K2, P;
    SK(a, b, H, A, B, K1, K2, P);
    fr << K1 << " " << K2 << endl;
    fr << "pelnas " << P << " Lt";

    return 0;
}
