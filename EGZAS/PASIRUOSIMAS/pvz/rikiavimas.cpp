#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
void nuskaitymas (int A[], int & n)
{
	ifstream fd ("duomenys.txt");
	fd>>n;
	for (int i=0;i<n;i++)
	    fd>>A[i];
	fd.close();
}
void rikiuoti (int A[], int n)
{
int t, laik;
	for(int i=0; i<n-1; i++)
	{
		laik=i;
		for(int z=i+1; z<n; z++)
		{
			if(A[z]<A[laik]) laik=z;
		}
		 t=A[laik];
		 A[laik]=A[i];
		 A[i]=t;
	}
}
void spausdinti (int A[], int n, int T[],int m)
{
	ofstream fr ("rez.txt");
     for (int i=0;i<n;i++)
       fr <<A[i]<<" ";
     fr <<endl;
	  for (int i=0;i<m;i++)
	    fr<<T[i]<<  " ";
    fr.close();
}
int main()
{   int A[100],n,T[100],m=0;
    nuskaitymas(A,n);
    for (int i=0;i<n;i++)
	    if (A[i]>0) {T[m]=A[i];m++;	}
	
    rikiuoti (A,n);
    rikiuoti (T,m);
    spausdinti (A,n,T,m);
    
	
    return (0);
}

