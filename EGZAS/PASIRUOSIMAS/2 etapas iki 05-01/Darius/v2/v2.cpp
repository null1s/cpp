#include <iostream>;
#include<fstream>;
using namespace std;
void laik(int &a, int &b, int liko, int i) {

    int val, t;
    b=liko+b;
if ((b/60)>=1) {
    val=b/60;
    b-=val*60;
    a+=val;
}
if ((a/24)>=1)
    t=a/24;
    a-=t*24;
}
int main() {
    int val, min, n;
    double greit, atst, liko;
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    fd>>val>>min>>n;
    for(int i=1; i<=n; i++) {
       fd>>atst>>greit;
        liko=atst/greit*60;
        laik(val, min, liko, i);
        fr<<i<<" "<<val<<" "<<min<<endl;
    }
    fd.close();
    fr.close();
    return 0;
}