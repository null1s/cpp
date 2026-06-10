#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
int A[100], B[100], C[100], t=0, n=0, k=0, a=0, b=0, c=0;
ifstream fd ("duom.txt");
ofstream fr ("rez.txt");
fd>>n;
for(int i=0; i<n; i++){
	fd>>t>>k;
	if (k>=1&&k<=3){
	A[a]=t;
	a++;
}
	else if (k>=4&&k<=6){
	B[b]=t;
	b++;
} 
	else if (k>=7&&k<=10){
	C[c]=t;
	c++;
}
}
fr<<"Pirmasis: ";
for(int i=0; i<a; i++) fr<<A[i]<<" ";
fr<<endl<<"Antrasis: ";
for(int i=0; i<b; i++) fr<<B[i]<<" ";
fr<<endl<<"Treciasis: ";
for(int i=0; i<c; i++) fr<<C[i]<<" ";

fd.close();
fr.close();
return 0;
}
