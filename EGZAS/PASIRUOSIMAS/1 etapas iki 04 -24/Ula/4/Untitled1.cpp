#include<iostream>
#include<fstream>
using namespace std;

struct mokiniai
{
	int numeris;
	int balas;
};

int main()
{
	
mokiniai A[50];
mokiniai y;

ifstream fd("duom.txt");
ofstream fr("rez.txt");

int n, x;

fd>>n;
for (int i=0; i<n; i++)
{
	fd>>A[i].numeris>>A[i].balas;
}

for (int i=0; i<n; i++)
{
	x=i;
    	
for (int j=i+1; j<n; j++)
{
	if(A[j].balas<A[x].balas) x=j;
}
y=A[x];
A[x]=A[i];
A[i]=y;
}

fr<<"Pirmasis: ";
for (int i=0; i<n; i++)
{
	if (A[i].balas<4) fr<<A[i].numeris<<" ";
}

fr<<endl<<"Antrasis: ";
for (int i=0; i<n; i++)
{
	if (A[i].balas>=4 && A[i].balas<=6) fr<<A[i].numeris<<" ";
}

fr<<endl<<"Treciasis: ";
for (int i=0; i<n; i++)
{
	if (A[i].balas>6) fr<<A[i].numeris<<" ";
}

fd.close();
fr.close();
return 0;
}

