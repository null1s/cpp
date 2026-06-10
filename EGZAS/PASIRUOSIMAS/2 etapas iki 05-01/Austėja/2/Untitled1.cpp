#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int atbulas(int s)
{
	int at=0;
	while(s>0)
	{
		at=at*10+(s%10);
		s=s/10;
	}
	return at;
}
int main ()
{ int n, m, sk=0;
   ifstream fd ("duom.txt");
   ofstream fr ("rez.txt");
fd>>n>>m;

for (int i=n; i<=m; i++)
{
	if(i==atbulas(i)) sk++;
}

cout<<sk;
   fd.close();
   fr.close();
   
return 0;
}

