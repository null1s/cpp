#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
ifstream fd ("duom.txt");
ofstream fr ("rez.txt");

int a=15, b=19, sk=0; //raðiau skaièius, nes nenuskaito ið duomenø.
fd>>a>>b;
fr<<"skaicius | dalijasi is:"<<endl;
for(int i=a; i<=b; i++)
{
	fr<<i<<"           ";
	for(int j=2; j<=i; j++)
	{
		if(i % j == 0 && i !=j) sk++;
	}
	fr<<sk<<endl;
}


fd.close();
fr.close();
return 0;
}
