#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

struct moksleiviai
{
	int dienos;
	int uzdaviniai[100];
	int kiekis;
};

int main()
{
moksleiviai A[100];

ifstream fd("duom.txt");
ofstream fr("rez.txt");

   int n, suma=0;
   fd>>n;
   for (int i=0; i<n; i++)
   {
   	  fd>>A[i].dienos;
   	  for (int j=0; j<A[i].dienos; j++)
   	  {
   	  	 fd>>A[i].uzdaviniai[j];
	  }
   }
   
   for (int i=0; i<n; i++)
   {
   	for (int j=0; j<A[i].dienos; j++)
   	{
   		A[i].kiekis=A[i].kiekis+A[i].uzdaviniai[j];
	}
   }
   
   for (int i=0; i<n; i++)
   {
   	  suma=A[i].kiekis+suma;
   }
   
   for (int i=0; i<n; i++)
   {
   	  fr<<A[i].kiekis<<endl;
   }
   fr<<suma;

fd.close();
fr.close();
return 0;
}

