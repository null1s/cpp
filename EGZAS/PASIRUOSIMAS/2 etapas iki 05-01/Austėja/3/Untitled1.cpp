#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
using namespace std;
double kaina(int kiek, double x, double y, double z)
{
	if(kiek<10) return kiek*x;
	if(kiek>=10 && kiek<=19) return kiek*y;
	return kiek*z;
}
int main ()
{ int n, a, b;
double x, y, z;
   ifstream fd ("duom.txt");
   ofstream fr ("rez.txt");
   
   fd>>n>>a>>b>>x>>y>>z;
   
   double bendr=kaina(n,x,y,z);
   double mokin=kaina(a,x,y,z);
   double mokyt=kaina(b,x,y,z);
   double suvaik=kaina(n+4,x,y,z);
   double vienam=suvaik/n;
   
   cout<<fixed<<setprecision(2);
   cout<<bendr<<" "<<mokin<<" "<<mokyt<<endl;
   cout<<suvaik<<endl;
   cout<<vienam<<endl;
   fd.close();
   fr.close();
   
return 0;
}

