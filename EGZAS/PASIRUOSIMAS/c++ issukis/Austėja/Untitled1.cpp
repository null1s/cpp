#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
bool pirminis(int x)
{
	if(x<2) return false;
	for(int i=2; i<x; i++)
	{
		if(x%i==0) return false;
	}
	return true;
}

int dregme(string diena)
{
	if(diena == "Pirmadienis") return 80;
	if (diena == "Antradienis") return 75;
	if(diena == "Treciadienis") return 95;
	if (diena =="Ketvirtadienis") return 50;
	if( diena == "Penktadienis") return 66;
	if (diena == "Sestadienis") return 87;
	return 92;
}
int main ()
{ int n;
   ifstream fd ("duom.txt");
   ofstream fr ("rez.txt");
   fd>>n;
   string dienos[100];
   int temp[100];
   
   for(int i=0; i<n; i++)
   {
   	fd>>dienos[i]>>temp[i];
   }
   
   cout<<"1 ir 2, pagal dienas: "<<endl;
   string savdien[]={"Pirmadienis", "Antradienis", "Treciadienis", "Ketvirtadienis", "Penktadienis", "Sestadienis", "Sekmadienis"};
   
   for(int i=0; i<7; i++)
   {
   	int dtemp[100];
   	int kiek=0;
   	
   	for (int j=0; j<n; j++)
   	{
   		if(dienos[j]==savdien[i])
   		{
   		dtemp[kiek]=temp[j];
		   kiek++	
		}
	}
	
   }
   fd.close();
   fr.close();
   
return 0;
}

