#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
double atstumas(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}
double plotas(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    double x1, y1, x2, y2, x3, y3;
    fd >> x1 >> y1;
    fd >> x2 >> y2;
    fd >> x3 >> y3;
    double a = atstumas(x1, y1, x2, y2);
    double b = atstumas(x2, y2, x3, y3);
    double c = atstumas(x1, y1, x3, y3);
    double S = plotas(a, b, c);
    fr << fixed << setprecision(2) << S;
    fd.close();
    fr.close();
    return 0;
}
