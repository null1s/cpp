#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
ifstream fd ("duom4.txt");
ofstream fr ("rez4.txt");

int mokiniai, numeris, balas;
int P[10], A[10], T[10];

int pirmas = 0, antras = 0, trecias = 0;
fd >> mokiniai;

for(int i = 0 ; i < mokiniai ; i++)
{
	fd >> numeris >> balas;
	
	if (balas <= 3)
	{
		P[pirmas] = numeris;
		pirmas++;
	} 
	else if (balas >= 7)
	{
		T[trecias] = numeris;
		trecias++;
	}
	else
	{
		A[antras] = numeris;
		antras++;
	}
}

fr << "Pirmasis: ";
for(int i = 0 ; i < pirmas ; i++)
{
	fr << P[i] << " ";
}

fr << endl << "Antrasis: ";
for(int i = 0 ; i < antras ; i++)
{
	fr << A[i] << " ";
}

fr << endl << "Treciasis: ";
for(int i = 0 ; i < trecias ; i++)
{
	fr << T[i] << " ";
}


fd.close();
fr.close();
return 0;
}
