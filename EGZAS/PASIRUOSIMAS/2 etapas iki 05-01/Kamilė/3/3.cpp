#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
double kaina(int zmones, double x, double y, double z) {
    if (zmones < 10) return x;
    else if (zmones <= 19) return y;
    else return z;
}
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int n, a, b;
    double x, y, z;
    fd >> n >> a >> b;
    fd >> x >> y >> z;
    double sumaA = a * kaina(a, x, y, z);
    double sumaB = b * kaina(b, x, y, z);
    double sumaViso = sumaA + sumaB;
    int visi = n + 4;
    double suma2 = visi * kaina(visi, x, y, z);
    double vienam = suma2 / n;
    fr << fixed << setprecision(2);
    fr << sumaViso << " " << sumaA << " " << sumaB << endl;
    fr << suma2 << endl;
    fr << vienam << endl;
    fd.close();
    fr.close();
    return 0;
}
