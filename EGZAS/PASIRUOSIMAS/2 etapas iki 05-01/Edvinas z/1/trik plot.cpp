#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
struct Taskas {
    double x;
    double y;
};
double skaiciuotiAtstuma(Taskas t1, Taskas t2) {
    return sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2));
}
double skaiciuotiPlota(Taskas A, Taskas B, Taskas C) {
    double a = skaiciuotiAtstuma(A, B);
    double b = skaiciuotiAtstuma(B, C);
    double c = skaiciuotiAtstuma(C, A);
   
    double p = (a + b + c) / 2.0;
   
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    Taskas A, B, C;

    fd >> A.x >> A.y;
    fd >> B.x >> B.y;
    fd >> C.x >> C.y;

    double plotas = skaiciuotiPlota(A, B, C);

    fr << fixed << setprecision(2) << plotas << "\n";

    fd.close();
    fr.close();

    return 0;
}
