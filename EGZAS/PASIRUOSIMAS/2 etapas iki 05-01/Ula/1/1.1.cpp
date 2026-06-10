#include<fstream>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void ilgis (int x, int y, int x1, int y1, double & CC)
{
	int XX; int YY;
	
	if (x>x1)
	{
		XX=x-x1;
	}
	else if (x<x1)
	{
		XX=x1-x;	
	}
	
	if (y>y1)
	{
		YY=y-y1;	
	}
	else if (y<y1)
	{
		YY=y1-y;	
	}
	
	CC=sqrt(pow(XX,2)+pow(YY,2));
}

void plotas (double PP, double A, double B, double C, double p, double & S)
{
	PP=A+B+C;
	p=(double)PP/2;
	S=sqrt(p*(p-A)*(p-B)*(p-C));
}

int main ()
{
	ifstream fd("duom.txt");
	ofstream fr ("rez.txt");
	
	double S, p, PP=0, A, B, C;
	int ax, ay, bx, by, cx, cy;
	fd>>ax>>ay>>bx>>by>>cx>>cy;
	
	ilgis(ax,ay,bx,by,A);
	ilgis(bx,by,cx,cy,B);
	ilgis(cx,cy,ax,ay,C);
    plotas(PP,A,B,C,p,S);
	
	fr<<fixed<<setprecision(2)<<S;
	
	fd.close();
	fr.close();
return 0;
}




