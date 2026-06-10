#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main ()
{ int a, b;
   ifstream fd ("duom.txt");
   ofstream fr ("rez.txt");
fd>>a>>b;

int d;
for(int i=a; i<=b; i++)
{
	d=0;
	for(int j=2; j<i; j++)
	{
	if (i%j==0) d++;
	}
	cout<<i<<" "<<d<<endl;
}
   fd.close();
   fr.close();
   
return 0;
}

