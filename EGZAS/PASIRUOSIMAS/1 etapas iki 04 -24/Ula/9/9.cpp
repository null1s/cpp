#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
	
	int a, b, did=0, A[100], y=1, sk=0, skaicius, kiek=0;
	fd>>a>>b;
	
	for (int i=a; i<=b; i++)
	{
		sk=0;
		while (y<=i)
		{
			if (i%y==0) sk++;
			y++;
		}
		
		if (sk>did) 
		{
			did=sk;
			skaicius=i;
		}
		y=1;
	}
	
	for (int y=1; y<=skaicius; y++)
	{
	   if (skaicius%y==0) 
	   {
			A[kiek]=y;
			kiek++;
	   }
	}
	
	fr<<"Skaicius "<<skaicius<<" turi daugiausia dalikliu "<<did<<endl;
	for (int i=0; i<did; i++)
	{
		fr<<A[i]<<" ";
	}

	
	fr.close();
    fd.close();
return 0; 
}
