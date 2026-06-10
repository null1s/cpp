#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
double kaina(double n, double x, double y, double z, int ats) {
    double k;
    double t=0, m=n+4;

    if (ats==1) {
        if (n<10) t=x;
    if (n>=10&&n<20) t=y;
    if (n>=20&&n<=30) t=z;
    k= n*t;
}
    if (ats==2||ats==3) {
    if (m<10) t=x;
    if (m>=10&&m<20) t=y;
    if (m>=20&&m<=30) t=z;
    }
    if (ats==2) k= m*t;
    if (ats==3) k= m*t/n;

    return k;
}
int main() {

    double n, m, mok, x, y, z;
    int ats;
    ifstream fd ("duom.txt");
    ofstream fr ("rez.txt");
fd>>n>>m>>mok>>x>>y>>z;
    ats=1;
    fr<<fixed<<setprecision(2)<<kaina(n, x, y, z, ats) <<" "<<kaina(m, x, y, z, ats)<<" "<<kaina(mok, x, y, z, ats)<<endl;
    ats=2;
    fr<<kaina(n, x, y, z, ats)<<endl;
    ats=3;
    fr<<kaina(n, x, y, z, ats)<<endl;
    fd.close();
    fr.close();
    return 0;
}