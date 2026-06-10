#include<iostream>
#include<conio.h>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;
double ilgis(int x1, int y1, int x2, int y2)
{
	double l=sqrt( pow(x2-x1,2)+pow(y2-y1,2) );
	return l;
}
double plotas(int ax, int ay, int bx, int by, int cx, int cy)
{
	double S=abs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by))/2.0;
	return S;
	}
int main ()
{ int ax, ay, bx, by, cx, cy;
double plot;
   ifstream fd ("duom.txt");
   ofstream fr ("rez.txt");
   
   fd>>ax>>ay>>bx>>by>>cx>>cy;
   
   double s=plotas(ax,ay,bx,by,cx,cy);
   
   cout<<fixed<<setprecision(2)<<s;
   fd.close();
   fr.close();
   
return 0;
}

