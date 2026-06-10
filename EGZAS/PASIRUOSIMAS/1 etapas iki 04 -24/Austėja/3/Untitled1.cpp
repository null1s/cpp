#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main ()
{ int n;
  double eur, lego;
   ifstream fd ("duom.txt");
   ofstream fr ("rez.txt");
   double sum=0;
   for (int i=0; i<6; i++)
   {
   	fd>>n;
   	for (int j=0; j<n; j++)
   	{
   	fd>>eur;
   	sum=sum+eur;
	}
   }
   fr<<sum<<endl;
   fd>>lego;
   if(sum>=lego) fr<<"Uþteks";
   else fr<<"Neuþteks";
   fd.close();
   fr.close();
   
return 0;
}

