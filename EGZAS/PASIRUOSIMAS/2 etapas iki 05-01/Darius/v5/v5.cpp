#include <iostream>
#include<fstream>
using namespace std;
void vartoj(double &a, double &b, double &c, double g){
a=g/100*a;
b=g/100*b;
c=g/100*c;
}
int dien(int g, int n) {
    int a;
        if ((g/100*349)>=1800) {
            a=1;
        }

else a=0;
    return a;
}
int main() {
    int n;
    double grik, a, b, c, diena=0, ta, tb, tc;
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    fd>>n>>a>>b>>c;
    for (int i=1;i<=n;i++) {
        ta=a;
        tb=b;
        tc=c;
        fd>>grik;
        diena+=dien(grik, n);
        vartoj(ta, tb, tc, grik);
        fr<<ta<<" "<<tb<<" "<<tc<<endl;

    }

fr<<"Vaida suvartojo reikima kaloriju kieki:"<<diena<<" dienas";








}
