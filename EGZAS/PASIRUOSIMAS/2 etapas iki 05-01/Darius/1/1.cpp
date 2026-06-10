#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
double atstum(double x1, double y1, double x2, double y2) {
    double viso;
    viso=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return viso;
}
double plotas(double a, double b, double c) {
    double S, p=(a+b+c)/2;
    S=sqrt(p*(p-a)*(p-b)*(p-c));
    return S;
}
int main() {
    double x1, y1, x2, y2, x3, y3;
    ifstream fd ("duom.txt");
    ofstream fr ("rez.txt");
    fd>>x1>>y1>>x2>>y2>>x3>>y3;
fr<<fixed << setprecision(2)<<plotas(atstum(x1,y1,x2,y2), atstum(x2,y2,x3,y3),atstum(x1,y1,x3,y3));
    fd.close();
    fr.close();
    return 0;
}