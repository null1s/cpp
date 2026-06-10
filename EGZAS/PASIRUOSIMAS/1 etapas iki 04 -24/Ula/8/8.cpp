#include<fstream>
#include<iostream>
using namespace std;

struct kauliukas
{
	int kiekis;
	int taskai[100];
	int suma;
};

int main()
{
	kauliukas A[100];
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
	
	int n, suma=0, y, did=0, sk=0, k;
	fd>>n;
	
	for (int i=0; i<n; i++)
	{
		fd>>A[i].kiekis;
		for (int j=0; j<A[i].kiekis; j++)
		{
			fd>>A[i].taskai[j];
		}
	}
	
    for (int i=0; i<n; i++)
    {
    	suma=0;
    	k=0;
    	
		while (k<A[i].kiekis && A[i].taskai[k]%2!=0)
		{
			suma=suma+A[i].taskai[k];
			k++;
		}
		
		if (k<A[i].kiekis)
		{
			suma=suma+A[i].taskai[k];
		}
		
		A[i].suma=suma;
	}

	for (int i=0; i<n; i++)
	{
		y=i+1;
		fr<<y<<" - Zaidejas surinko "<<A[i].suma<<" tasku"<<endl;
	}
	
	for (int i=0; i<n; i++)
	{
		if (A[i].suma>did) 
		{
			did=A[i].suma;
			sk=i+1;
		}
	}
	fr<<"Zaidima laimejo "<<sk<<" zaidejas, jis surinko "<<did<<" tasku";
	
	fr.close();
    fd.close();
return 0; 
}
