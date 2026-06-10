#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

void skaitymas (int & n, double A[100])
{
	ifstream fd("duom.txt");
    fd>>n;
    for (int i=0; i<n; i++)
    {
    	fd>>A[i];
	}
	fd.close();
}

double vidurkis (int n, double A[100])
{
	double vid, suma=0;
	for (int i=0; i<n; i++)
	{
		suma+=A[i];
	}
	vid=(double)suma/n;
	return vid;
}

void salinimas (int & n, int & i, double A[100])
{
	for (int j=i;j<=n;j++)
	{
		A[j] = A[j+1];
	}
    n--; 
	i--;
}

void suradimas (int & n, double vid, double A[100])
{
	for (int i=0; i<n; i++)
	{
		if (A[i]<vid)
		{
			salinimas(n,i,A);
		}
	}
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

void spausdinimas (int n,double A[100])
{
	ofstream fr("rez.txt");
	fr<<"Finale dalyvaus "<<n<<" mokiniai"<<endl;
	fr<<"Ju pasiekti rezultatai:"<<endl;
	for (int i=0; i<n; i++)
	{
		fr<<fixed<<setprecision(2)<<A[i]<<" ";
	}
	fr.close();
}

int main()
{
	int n;
	double A[100], vid;
	
	skaitymas(n,A);
	vid=vidurkis(n,A);
	suradimas(n,vid,A);
	rikiavimas(n,A);
	spausdinimas(n,A);
	
return 0;
}
