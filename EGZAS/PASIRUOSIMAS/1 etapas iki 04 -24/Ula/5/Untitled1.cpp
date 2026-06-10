#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;

struct temperatura
{
	double laipsniai;
	double skirtumas;
};

int main()
{
   temperatura x;
   int n=0; 
   double did=0;

   ifstream fd("duom.txt");
   ofstream fr("rez.txt");

   while (fd>>x.laipsniai)
   {
	  n++;
   }   
   
   fd.clear();
   fd.seekg(0);
   
   temperatura A[n];
   
   for (int i=0; i<n; i++)
   {
   	  fd>>A[i].laipsniai;
   }
   
   for (int i=1; i<n; i++)
   {
   	   fr<<fixed<<setprecision(1)<<A[i-1].laipsniai<<endl;

	   if (A[i-1].laipsniai>A[i].laipsniai)
   	   {
   	   	 A[i].skirtumas=A[i].laipsniai-A[i-1].laipsniai;
   	   	 fr<<"   ("<<A[i].skirtumas<<")"<<endl;
	   }
	   
	   else if (A[i-1].laipsniai<A[i].laipsniai)
	   {
	   	 A[i].skirtumas=A[i].laipsniai-A[i-1].laipsniai;
   	   	 fr<<"   (+"<<A[i].skirtumas<<")"<<endl;
	   }
	   
	   else 
	   {
	   	 A[i].skirtumas=A[i].laipsniai-A[i-1].laipsniai;
   	   	 fr<<"   (+"<<A[i].skirtumas<<")"<<endl;
	   }
   }
   fr<<A[n-1].laipsniai<<endl;
   
   for (int i=0; i<n; i++)
   {
   	  if (fabs(A[i].skirtumas)>fabs(did)) did=A[i].skirtumas;
   }
   
   fr<<"--------------------"<<endl;
   fr<<"Dienu skaicius: "<<n<<endl;
   
   if (did>0 || did==0) fr<<"Didziausias temperaturos pokytis: "<<endl<<"+"<<did;
   else if (did<0) fr<<"Didziausias temperaturos pokytis: "<<endl<<did;
  
   
fd.close();
fr.close();
return 0;
}

