#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

struct vaikai
{
	string vard;
	int lt;
	int ct;
	int centai;
	int d;
	double islaidos=0;
	int paaukoti=0;
};

int main()
{
	vaikai A[100];
	
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
    int n, kiekis, did=0, sk, suma=0;
    double kaina;
    
    fd>>n;
    for (int i=0; i<n; i++)
    {
    	fd.ignore();
		char eil[15];
    	fd.get(eil,15);
    	A[i].vard=eil;
		fd>>A[i].lt>>A[i].ct>>A[i].d;
    	for (int j=0; j<A[i].d; j++)
    	{
    		fd>>kiekis>>kaina;
    		A[i].islaidos+=kiekis*kaina;
		}
	}
	
	for (int i=0; i<n; i++)
	{
		A[i].centai=A[i].lt*100+A[i].ct;
		A[i].paaukoti=A[i].centai-A[i].islaidos*100;
		if (A[i].paaukoti>did) 
		{
			did=A[i].paaukoti;
			sk=i;
		}
		suma+=A[i].paaukoti;
	}
	
	for (int i=0; i<n; i++)
	{
		cout<<A[i].vard<<A[i].paaukoti/100<<" "<<A[i].paaukoti%100<<endl;
	}
	cout<<suma/100<<" "<<suma%100<<endl;
	cout<<A[sk].vard<<did/100<<" "<<did%100;
	
	
    
    fd.close();
    fr.close();
return 0;
}

