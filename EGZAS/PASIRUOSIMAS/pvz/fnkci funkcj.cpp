#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
using namespace std;
//--------------------------
int kaina(int v, int e)
{   int k;
	if (v == 0) k =0;
	   else if(e == 1 || e == 2) k=100;
	        else if (e == 3 || e == 4)  k = 70;
	                 else k = 40; 
	return k;
}
//--------------------------
void skaiciuoti (int kaina,int & kiek, int & suma, double & vid)
{
	if (kaina >0)
	{
		kiek ++;
		suma += kaina;
	    vid = (double) suma/kiek;
	}
}
//--------------------------
int main()
{   int eil, viet, v,k=0,suma;
double vid;
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
	
    fd>>eil; fd>> viet;
    for (int i=1;i<=eil;i++)
    {
    	for (int j=1;j<=viet; j++)
    	{
    		fd>> v;
    		skaiciuoti(kaina(v,i),k, suma,vid);
		}
	}
  fr<<suma<<" "<<fixed<<setprecision(2)<<vid;
    fd.close();
    fr.close();
return 0;
}

