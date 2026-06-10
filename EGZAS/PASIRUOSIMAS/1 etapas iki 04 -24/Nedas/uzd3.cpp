#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
ifstream fd ("duom3.txt");
ofstream fr ("rez3.txt");

int kartai;
double pinigai, kaina, visi_pinigai = 0;


for (int i = 0 ; i < 6 ; i++)
{
	fd >> kartai;
	for (int j = 0 ; j < kartai ; j++)
	{
		fd >> pinigai;
		visi_pinigai = visi_pinigai + pinigai;
	}
}

fd >> kaina;
fr << visi_pinigai << endl;

if(visi_pinigai >= kaina) fr << "Uzteks";
else fr << "Neuzteks";

fd.close();
fr.close();
return 0;
}


