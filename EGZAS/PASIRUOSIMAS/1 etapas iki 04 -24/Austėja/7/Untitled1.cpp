#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main ()
{ int n, gn, gs, k;
   ifstream fd ("duom.txt");
   ofstream fr ("rez.txt");
   fd>>n;
   int sum1=0;
   int sum2=0;
   int sum3=0;
   int sum4=0;
   for(int i=0; i<n; i++)
   {
   	fd>>gn>>gs;
   	for(int j=0; j<gs; j++)
   	{
   	fd>>k;
   	if(gn==1) sum1=sum1+k;
   	else if (gn==2) sum2=sum2+k;
   	else if (gn==3) sum3=sum3+k;
   	else if (gn==4) sum4=sum4+k;
	}
   }
   fr<<"Pjaustykliu: "<<sum1<<" Eur"<<endl;
   fr<<"Virduliu: "<<sum2<<" Eur"<<endl;
   fr<<"Mikseriu: "<<sum3<<" Eur"<<endl;
   fr<<"Plaktuviu: "<<sum4<<" Eur"<<endl;
   int max=sum1;
   string pavad = "Pjaustykliu ";
   if(sum2>max) 
   {
   	max=sum1;
   	pavad = "Virduliu ";
   }
   if(sum3>max)
   {
   	max=sum3;
   	pavad = "Mikseriu ";
   }
   if(sum4>max)
   {
   	max=sum4;
   	pavad = "Plaktuviu ";
   }
   fr<<pavad<<"pagaminta didziausiai sumai";
   fd.close();
   fr.close();
   
return 0;
}

