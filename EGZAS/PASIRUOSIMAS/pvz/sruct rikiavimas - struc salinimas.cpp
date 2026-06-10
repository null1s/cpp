//sukurkite sarağa lankytoju sumokëjusiu didesne nei nurodyta kaina, kainos didejimo tvarka.
// pirmoje eilutëje duota vardas pirkëjø kiekis ( nedaugiau 100)  ir ribinë kaina
//antroje eilutëje vardas (10simb) ir pavardë (15 simb), pirktu prekiu kiekis ir kaina;    
// (pakeisti programa kai duotas vardas su tarpais)
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;
struct pirkejas
    {
     string var;
     string pav;
     int kiek;
     double kain, suma;
};
void skaitymas (pirkejas A[], double & k, int & n)
{
  	ifstream fd ("duom.txt");
  	fd>>n;fd>>k;
  	fd.ignore();
  	for (int i=1; i<=n;i++)
  	{
  	fd>>(A[i].var);   
	fd>>(A[i].pav);
    fd>>A[i].kiek;
    fd>>A[i].kain;
    /* nuskaito 10 ismboliu net su tarpais ir pavercia string
	char var[10];
	fd.get(var,10);
	A[i].var=var;
	fd.ignore();*/  
	//pakartoti su pavardemis ar kitais kintamaisiais jei reikia
    A[i].suma = A[i].kiek * A[i].kain;
    }
  fd.close();
}
void pasalinti (pirkejas A[], double k, int & n)
{
	for (int i = 1; i<=n; i++)
	{
	if (A[i].suma < k)
	    {
	    for (int j = i; j<n; j++)
	   	    A[j]=A[j+1];
	   	n=--;i--;
       }
   }
}
void rikiuoti (pirkejas A[], int &n)
{
    int d; 
	pirkejas elem;
for (int i=1; i<=n-1; i++)
    {
        d=i;
        for (int j = i+1; j<=n; j++)
            if (A[j].suma < A[d].suma) d=j;
        {
        elem = A[i];
        A[i] = A[d];
        A[d] = elem;
        }
    }
}
void spausdinti (pirkejas A[], int & n)
{
	ofstream fr ("rez.txt");
	for (int i=1; i<=n;i++)
  	{
  	fr << A[i].var<<" "<<A[i].pav<<" "<<A[i].kiek<<" "<<A[i].kain<<" "<<A[i].suma<<endl;
    }
	fr.close();
}
int main()
{   pirkejas A[100];
    double r_kain;
    int n;
skaitymas (A, r_kain, n);
pasalinti(A,r_kain,n);
rikiuoti(A,n);
spausdinti (A, n) ;
    
return 0;
}

