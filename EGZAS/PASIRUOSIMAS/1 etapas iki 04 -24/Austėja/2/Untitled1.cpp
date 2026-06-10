#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main ()
{ int n, d, uzd, summ=0, sumv=0;
   ifstream fd ("duom.txt");
   ofstream fr ("rez.txt");
fd>>n;
for(int i=0; i<n; i++)
{ fd>>d;
	for(int j=0; j<d; j++)
	{
		fd>>uzd;
		summ=uzd+summ;
	}
	fr<<summ<<endl;
	sumv=summ+sumv;
    summ=0;
}
fr<<sumv;
   fd.close();
   fr.close();

return 0;
}

