#include <iostream>
#include <fstream>
using namespace std;
struct tr{
int a=0;
    int b=0;
    int c=0;
};
void skaic(int &n, tr &A, int &p1, int p2, int p3, int &max1, int &max2, int &max3) {
    A.a=p1+p2+p3;
    if (p1>5) A.b+=1;
    else if (p1<5) A.c+=1;
    if (p2>6) A.b+=1;
    else if (p2<6) A.c+=1;
    if (p3>4) A.b+=1;
    else if (p3<4) A.c+=1;
    max1+=A.a;
    max2+=A.b;
    max3+=A.c;
}
int main() {
    int n=0, p1=0, p2=0, p3=0, max1=0, max2=0, max3=0;
    tr A[100];
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    fd>>n;
    for (int i = 0; i <n; i++) {
        fd>>p1>>p2>>p3;
        skaic(i, A[i], p1, p2, p3, max1, max2, max3);
    }
    for (int i = 0; i <n; i++) {
        fr<<A[i].a<<" "<<A[i].b<<" "<<A[i].c<<endl;
    }
    fr<<max1<<" "<<max2<<" "<<max3<<endl;

}