#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

void skaitymas (int & n, int & m, double A[10], double B[10])
{
	ifstream fd("duom1.txt");
	ifstream fe("duom2.txt");
    fd>>n;
    for (int i=0; i<n; i++)
    {
    	fd>>A[i];
	}
	fe>>m;
	for (int i=0; i<m; i++)
	{
		fe>>B[i];
	}
	fe.close();
	fd.close();
}

void salinimas_iterpimas (int n, int m, double A[10], double B[10])
{
/*/	for (int i=0; i<m+n; i++)
	{
		A[n+i]=B[i];
	}
	
	double maz=A[0];
	for (int j=0; j<5; j++)
	{
		for (int i=0; i<m+n; i++)
    	{
	    	if (A[i]<maz) maz=A[i];
    	}
    	for (int i=0; i<m+n; i++)
    	{
    		if (A[i]==maz)
    		{
    			int x;
    	        x=m+n;
				for(int k=i;k<x;k++) A[k] = A[k+1];
    		    x--; i--;
			}
		}
	}/*/

	/*/
	for (int j=i;j<=n;j++)
	{
		A[j] = A[j+1];
	}
    n--; 
	i--;/*/
}

void rikiavimas (int n, double A[100])
{
	double t;
	int x;
	
	for(int i=0; i<n-1; i++)
	{
		x=i;
		for(int j=i+1; j<n; j++)
		{
			if(A[j]<A[x]) x=j;
		}
		 t=A[x];
		 A[x]=A[i];
		 A[i]=t;
	}
}

void spausdinimas ()
{
	ofstream fr("rez.txt");
	
	fr.close();
}

int main()
{
	int n, m;
	double A[10], B[10];
	
	skaitymas(n,m,A,B);
/*/	salinimas_iterpimas(n,m,A,B);/*/
	
	for (int i=0; i<m; i++)
	{
		A[n+i]=B[i];
	}
	
	double maz=A[0];
	for (int i=0; i<m+n; i++)
   	{
    	if (A[i]<maz) maz=A[i];
   	}
   	
	cout<<maz;
	
	double x;
	x=n+m-10;
	
	if (x>0)
	{
		for (int i=0; i<x; i++)
		{
			A[i] = A[i+1];
		}	
	}


       
	
return 0;
}
