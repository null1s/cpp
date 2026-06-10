#include <fstream>
using namespace std;
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int n;
    fd >> n;
    int nr, balas;
    int A[100], B[100], C[100];
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        fd >> nr >> balas;
        if (balas >= 1 && balas <= 3) {
            A[a++] = nr;
        } else if (balas >= 4 && balas <= 6) {
            B[b++] = nr;
        } else if (balas >= 7 && balas <= 10) {
            C[c++] = nr;
        }
    }
    fr << "Pirmasis: ";
    for (int i = 0; i < a; i++) {
        fr << A[i] << " ";
    }
    fr << endl;
    fr << "Antrasis: ";
    for (int i = 0; i < b; i++) {
        fr << B[i] << " ";
    }
    fr << endl;
    fr << "Treciasis: ";
    for (int i = 0; i < c; i++) {
        fr << C[i] << " ";
    }
    fr << endl;
    fd.close();
    fr.close();
    return 0;
}
