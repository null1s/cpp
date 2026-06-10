#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
double pinig(int i, int k) {
int t;
    if (i<=2&&k==1) t=100;
    if (i>2&&i<=4&&k==1) t=70;
    if (i>4&&k==1) t=40;
    return t;
}
void rez(double &sum, double &vid) {
    int k=0, a, b, n;
    ifstream fd ("duom.txt");

    fd>>a>>b;
for (int i=1; i<=a; i++) {
    for (int j=0; j<b; j++) {
        fd>>k;
        sum+= pinig(i, k);
        if (k==1) n++;
    }
}
    vid=sum/n;

    fd.close();

}
int main() {
    ofstream fr ("rez.txt");
    double sum=0, vid=0;
    rez(sum, vid);
    fr<<sum<<" "<<fixed<<setprecision(2)<<vid<<endl;
    fr.close();
    return 0;
}