#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
struct salys
{
	int anglija[4];
	int prancuzija[4];
	int did_a;
	int did_p;
};

void skaitymas (int & na, int & np, salys A[100])
{
	ifstream fd("anglija.txt");
    ifstream fe("prancuzija.txt");
    
    fd>>na;
    fe>>np;
    
    for (int i=0; i<na; i++)
    {
    	for (int j=0; j<4; j++)
    	{
    		fd>>A[i].anglija[j];
		}
	}

	for (int i=0; i<np; i++)
    {
    	for (int j=0; j<4; j++)
    	{
    		fe>>A[i].prancuzija[j];
		}	
	}
    
    fe.close();
	fd.close();
}

void didziausios_reiksmes (int na, int np, salys A[100])
{
    int dida=0, didp=0;
    for (int i=0; i<na; i++)
    {
    	for (int j=0; j<4; j++)
    	{
    		if (A[i].anglija[j]>dida)
			{
    			dida=A[i].anglija[j];
			}
		}
		A[i].did_a=dida;
		dida=0;
	}
	
	for (int i=0; i<np; i++)
    {
    	for (int j=0; j<4; j++)
    	{
    		if (A[i].prancuzija[j]>didp)
			{
    			didp=A[i].prancuzija[j];
			}
		}
		A[i].did_p=didp;
		didp=0;
    }
}

void laimejimai (int np, int na, salys A[100], int & ska, int & skp)
{
	for (int i=0; i<na; i++)
	{
		if (A[i].did_a>A[i].did_p) ska++;
		else if (A[i].did_a<A[i].did_p) skp++;
	}
}

void spausdinimas (int ska, int skp)
{
	ofstream fr("rez.txt");
	
    fr<<"Anglija surinko: "<<ska<<endl;
    fr<<"Prancuzija surinko: "<<skp<<endl;
    if (ska>skp) fr<<"Laimejo: Anglija";
    else if (ska<skp) fr<<"Laimejo: Prancuzija";
    else fr<<"Lygiosios";
    
	fr.close();
}

int main()
{
	salys A[100];
	int na, np, ska=0, skp=0;
	skaitymas(na,np,A);
	didziausios_reiksmes(na,np,A);
	laimejimai(np,na,A,ska,skp);
	spausdinimas(ska,skp);
	
return 0;
}
