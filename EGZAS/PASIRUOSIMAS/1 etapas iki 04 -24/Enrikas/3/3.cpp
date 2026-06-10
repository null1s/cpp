#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
ifstream fd ("duom3.txt");
ofstream fr ("rez3.txt");

int t;
double a, b, visi = 0;


for (int i = 0 ; i < 6 ; i++)
{
	fd >> t;
	for (int j = 0 ; j < t ; j++)
	{
		fd >> a;
		visi = visi + a;
	}
}

fd >> b;
fr << visi << endl;
if(visi >= b) fr << "Uzteks";
else fr << "Neuzteks";
fd.close();
fr.close();
return 0;
}


