#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
//--------funkcija dbd 
int dbd (int a, int b)
{
	int dbd, bdal;
	while (a%b!=0)
	{
		bdal=a%b;
		a=b;
		b=bdal;
	}
	return bdal;
}
int main()

{
	int sk, sk1, sk2;
ifstream fd("duomenys.txt"); ofstream fr("rez.txt");
fd>>sk;
fd>>sk1;
for (int i=2; i<=sk; i++)
{
	fd>>sk2;
	sk1 = dbd(sk1, sk2);
	
	
}
fr<<sk1;
fd.close(); fr.close();
return 0;

}

