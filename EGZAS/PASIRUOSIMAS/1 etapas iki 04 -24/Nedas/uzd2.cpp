#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
ifstream fd ("duom2.txt");
ofstream fr ("rez2.txt");

int moksleiviai, dienos, visi_uzdaviniai, uzdaviniai = 0 , mokinio_uzdaviniai;

fd >> moksleiviai;

for (int i = 0 ; i < moksleiviai ; i++)
{
	mokinio_uzdaviniai = 0;
	fd >> dienos;
	for (int i = 0 ; i < dienos ; i++)
	{
		fd >> uzdaviniai;
		mokinio_uzdaviniai = mokinio_uzdaviniai + uzdaviniai;
		visi_uzdaviniai = visi_uzdaviniai + uzdaviniai;
	}	
	fr << mokinio_uzdaviniai << endl;	
}
	fr << visi_uzdaviniai << endl;
	
fd.close();
fr.close();
return 0;
}


