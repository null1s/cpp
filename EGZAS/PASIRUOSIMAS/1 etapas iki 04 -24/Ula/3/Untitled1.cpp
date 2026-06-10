#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

struct pinigai
{
	int dienos;
	double kiekis[100];
};

int main()
{
pinigai A[100];

ifstream fd("duom.txt");
ofstream fr("rez.txt");

   int n=6;
   double suma=0, x;
  
   for (int i=0; i<n; i++)
   {
   	  fd>>A[i].dienos;
   	  for (int j=0; j<A[i].dienos; j++)
   	  {
   	  	 fd>>A[i].kiekis[j];
	  }
   }
   fd>>x;
   
   for (int i=0; i<n; i++)
   {
   	for (int j=0; j<A[i].dienos; j++)
   	{
   	   suma=suma+A[i].kiekis[j];	
	}
   }
   
   fr<<suma<<endl;
   if (suma>x) fr<<"uzteks";
   else if (suma<x) fr<<"neuzteks";
   else fr<<"uzteks";

fd.close();
fr.close();
return 0;
}

