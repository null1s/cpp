#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;

void skaitymas (int & n, int & k, int & nr, int A[100])
{
	ifstream fd("duom.txt");
	fd>>n>>k>>nr;
	for (int i=0; i<n; i++)
	{
		fd>>A[i];
	}
	fd.close();
}

void iterpimas (int A[100], int nr, int n)
{
	A[n]=nr;
}

void salinimas_iterpimas (int A[100], int n, int k, int nr)
{
	
}

void spausdinimas ()
{
	ofstream fr("rez.txt");
	
	fr.close();
}

int main()
{
	int n, k, nr, A[100];
	
	skaitymas(n,k,nr,A);
	iterpimas(A,nr,n);
	
	salinimas_iterpimas(A,n,k,nr);
	
	int i=0;
	while (A[i]!=nr)
	{
		i=abs((n+1)-k);
		cout<<i<<" ";
		i=0;
		n--;
    /*/	A[i] = A[i+1];	           	
    	
		n--;/*/
	}
	
	for (int i=0; i<n+1; i++)
	{
		cout<<A[i]<<" ";
	}
	
return 0;
}
