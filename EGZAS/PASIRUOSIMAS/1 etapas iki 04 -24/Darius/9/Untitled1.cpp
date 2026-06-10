#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
struct skaicius
    {
int sk;
int dalikl=0;
};
int main()
{
int n1, n2, max=0, maxs=0;
skaicius A[1000];
ifstream fd ("duom.txt");
ofstream fr ("rez.txt");
fd>>n1>>n2;
	for(int i=n1; i<=n2; i++){
	A[i].sk=i;
	for(int j=1; j<=i; j++){
	if (A[i].sk%j==0) A[i].dalikl++;
	
	}
}
	for(int i=n1; i<=n2; i++){
	if (A[i].dalikl>max){
	max=A[i].dalikl;
	maxs=i;
}
}
fr<<"Skaicius "<<A[maxs].sk<<" Turi daugiausia dalikliu "<<A[maxs].dalikl<<endl;
for(int i=1; i<=maxs; i++){
	if (A[maxs].sk%i==0) fr<<i<<" ";
}

fd.close();
fr.close();
return 0;
}

