#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main ()
{ int n, eil, bal;
   ifstream fd ("duom.txt");
   ofstream fr ("rez.txt");
   fd>>n;

int A[100], B[100];
for(int i=0; i<n; i++)
{
	fd>>A[i]>>B[i];
}

cout<<"Pirmasis: ";
for (int i=0; i<n; i++)
{
	if(B[i]>=1 && B[i]<=3) cout<<A[i]<<" ";
}
cout<<endl; 
 
cout<<"Antrasis: ";
for (int i=0; i<n; i++)
{
	if(B[i]>=4 && B[i]<=6) cout<<A[i]<<" ";
}
cout<<endl;

cout<<"Treèiasis: ";
for (int i=0; i<n; i++)
{
	if(B[i]>=7 && B[i]<=10) cout<<A[i]<<" ";
}
cout<<endl;
   fd.close();
   fr.close();
   
return 0;
}

