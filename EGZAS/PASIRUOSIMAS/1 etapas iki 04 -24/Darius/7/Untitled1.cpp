#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
int n=0, kod=0, n1=0, A[5], k=0, max=0;
ifstream fd ("duom.txt");
ofstream fr ("rez.txt");
fd>>n;
A[1]=0;
A[2]=0;
A[3]=0;
A[4]=0;
for(int i=0; i<n; i++){
	fd>>kod>>n1;
	for(int j=0; j<n1; j++){
	fd>>k;
	A[kod]+=k;
	}
}
fr<<"Pjaustykliu: "<<A[1]<<endl;
fr<<"Virduliu: "<<A[2]<<endl;
fr<<"Mikseriu: "<<A[3]<<endl;
fr<<"Plaktuviu: "<<A[4]<<endl;
fr<<"Pagaminta daugiausiai: ";
max=1;
if (A[2]>A[max]) max=2;
if (A[3]>A[max]) max=3;
if (A[4]>A[max]) max=4;

if (max==1) fr<<"Pjaustykliu";
else if (max==2) fr<<"Virduliu";
else if (max==3) fr<<"Mikseriu";
else if (max==4) fr<<"Plaktuviu";
fd.close();
fr.close();


return 0;
}

