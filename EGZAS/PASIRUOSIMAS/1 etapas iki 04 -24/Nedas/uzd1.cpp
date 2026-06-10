#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
ifstream fd ("duom1.txt");
ofstream fr ("rez1.txt");

int pradzia, pabaiga, dalijasi;

fd >> pradzia >> pabaiga;

fr << "Skaicius    |      Dalijasi is:" << endl;
for (int i = pradzia ; i <= pabaiga ; i++)
{
	dalijasi = 0;
	fr << i << "           ";
	for (int j = 2 ; j <= i ; j++) // nuo 2, nes neskaityti vieneto
	{
		if (i % j == 0 && i != j) dalijasi++;
	}
	fr << dalijasi << endl;
}


fd.close();
fr.close();
return 0;
}


