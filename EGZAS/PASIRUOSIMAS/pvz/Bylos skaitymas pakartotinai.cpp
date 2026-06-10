#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
void max_kuprine(int s,int & m)
{
	if (s > m) m = s;
}
void lyginti (int s, int m, int & k)
{
	if (s * 2 <= m) k++;
}
int main()
{   int k=0,kiekis, svoris,max_svor=0; 
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
    fd>>kiekis;
	for (int i=1; i<=kiekis;i++)
	{
	   fd>>svoris;	
	   max_kuprine(svoris, max_svor);
	}    
    fr <<max_svor<<" ";
    fd.clear(); 
    fd.seekg( 1 );
    for (int i=1; i<=kiekis;i++)
	{
	   fd>>svoris;	
	   lyginti (svoris, max_svor, k);
	}   
    fr <<k;
	fd.close();
    fr.close();
return 0;
}

