#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int dbd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void prastinti(int &sk, int &var) {
    int d = dbd(abs(sk), abs(var));
    sk /= d;
    var /= d;

    if (var < 0) { 
        sk = -sk;
        var = -var;
    }
}

void isvesti(ofstream &fr, int sk, int var) {
    if (var == 1)
        fr << sk;
    else
        fr << sk << "/" << var;
}

void skaiciuoti(int a, int b, int c, int d,
                int &sum_sk, int &sum_var,
                int &skirt_sk, int &skirt_var) {

    sum_sk = a * d + b * c;
    sum_var = b * d;

    skirt_sk = a * d - b * c;
    skirt_var = b * d;

    prastinti(sum_sk, sum_var);
    prastinti(skirt_sk, skirt_var);
}

int main() {
    ifstream fd("duom");
    ofstream fr("rez");

    int n;
    fd >> n;

    int A[100], B[100], C[100], D[100];

    for (int i = 0; i < n; i++) {
        fd >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i = 0; i < n; i++) {
        int s_sk, s_var, k_sk, k_var;

        skaiciuoti(A[i], B[i], C[i], D[i],
                   s_sk, s_var, k_sk, k_var);

        isvesti(fr, A[i], B[i]);
        fr << " + ";
        isvesti(fr, C[i], D[i]);
        fr << " = ";
        isvesti(fr, s_sk, s_var);

        fr << "   ";

        isvesti(fr, A[i], B[i]);
        fr << " - ";
        isvesti(fr, C[i], D[i]);
        fr << " = ";
        isvesti(fr, k_sk, k_var);

        fr << endl;
    }

    fd.close();
    fr.close();

    return 0;
}
