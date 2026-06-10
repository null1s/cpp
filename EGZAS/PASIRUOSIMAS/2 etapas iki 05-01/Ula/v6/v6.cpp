#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;

struct dienos
{
    int pir;
    int ant;
    int tre;
    int bendros;
    int virsijo;
    int nepasieke;
};

void savaite (dienos A[], int & suma, int & sumask, int & sumakk, int i)
{
	int sk=0;
	int kk=0;	
	
	A[i].bendros=A[i].pir+A[i].ant+A[i].tre;
	suma+=A[i].bendros;
		
	if (A[i].pir>5) sk++;
	else if (A[i].pir<5) kk++;
		
	if (A[i].ant>6) sk++;
	else if (A[i].ant<6) kk++;
		
	if (A[i].tre>4) sk++;
	else if (A[i].tre<4) kk++;
		
	A[i].virsijo=sk;
	A[i].nepasieke=kk;
	sumask+=sk;
	sumakk+=kk;
}

void rezultatai (int x, int y, int z)
{
    ofstream fr("rez.txt", ios::app);
    
    fr<<x<<" "<<y<<" "<<z<<endl;
    
    fr.close();
}

int main ()
{
    dienos A [100];
    
	ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    fr.close();

    int n, suma=0, sk=0, kk=0, sumask=0, sumakk=0;
    fd>>n;
    
    for (int i=0; i<n; i++)
    {
    	fd>>A[i].pir>>A[i].ant>>A[i].tre;
	}
	
	for (int i=0; i<n; i++)
	{
		savaite (A,suma,sumask,sumakk,i);
	}
	
	for (int i=0; i<n; i++)
	{
		rezultatai(A[i].bendros,A[i].virsijo,A[i].nepasieke);
	}
	rezultatai(suma,sumask,sumakk);

    fd.close();
    return 0;
}


