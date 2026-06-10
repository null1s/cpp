#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;

struct maistas
{
	int gramai;
	double angliavandeniai;
	double baltymai;
	double riebalai;
};

void abr (maistas A[], double ang, double bal, double rie, int n)
{
	for (int i=0; i<n; i++)
	{
		A[i].angliavandeniai=((double)A[i].gramai/100)*ang;
		A[i].baltymai=((double)A[i].gramai/100)*bal;
		A[i].riebalai=((double)A[i].gramai/100)*rie;
	}
}

void kalorijos (maistas A[], int & sk, int n)
{
	for (int i=0; i<n; i++)
	{
		if (((double)A[i].gramai/100)*349>=1800) sk++;
	}
}

int main ()
{
    maistas A [100];
    
	ifstream fd("duom.txt");
    ofstream fr("rez.txt");

    int n, sk=0;
    double ang, bal, rie;
    
    fd>>n>>ang>>bal>>rie;
    
    for (int i=0; i<n; i++)
    {
    	fd>>A[i].gramai;
	}
	
	abr(A,ang,bal,rie,n);
	for (int i=0; i<n; i++)
	{
		fr<<A[i].angliavandeniai<<" "<<A[i].baltymai<<" "<<A[i].riebalai<<endl;
	}
	
	kalorijos(A,sk,n);
    fr<<"Vaida suvartojo reikiama kaloriju kieki "<<sk<<" dienas";
    
    fd.close();
    fr.close();
    return 0;
}


