#include <iostream>
#include <fstream>
using namespace std;
int apv(int n,int sk) {
int apv=0, p=0, s=0, tikr=0;
for(int i=0;i<sk;i++) {
    s=n%10;
    tikr=tikr*10+s;
    n=n/10;
}
return tikr;
}
int main() {

    int n, m, sk, sk1=0, k=0;
ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    fd>>n>>m;
    while(n<=m) {
        sk=n;
        sk1=1;
        while (sk>=10) {
            sk=sk/10;
            sk1++;
        }
if (n==apv(n,sk1)) k++;

n++;
    }
fr<<k;
}