#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;

struct kelione
{
	int kilometrai;
	int greitis;
	int minutes;
	int h_galinis;
	int min_galinis;
};

void valandos(kelione A[], int h, int min, int m, int pradzia_h)
{
    pradzia_h=h*60+min;
	
	for (int i=0; i<m; i++)
	{
		A[i].minutes=trunc((double)A[i].kilometrai/A[i].greitis*60);
		pradzia_h+=A[i].minutes;
		
		A[i].h_galinis=pradzia_h/60;
        A[i].min_galinis=pradzia_h%60;
    }	
}

int main ()
{
    kelione A [100];
    
	ifstream fd("duom.txt");
    ofstream fr("rez.txt");

    int h, min, m, pradzia_h=0;
    fd>>h>>min>>m;
    
    for (int i=0; i<m; i++)
    {
    	fd>>A[i].kilometrai>>A[i].greitis;
	}
	
    valandos(A,h,min,m,pradzia_h);
    
    for (int i=0; i<m; i++)
	{
        if (A[i].h_galinis>=24)
		{
			A[i].h_galinis-=24;
			fr<<i+1<<" "<<A[i].h_galinis<<" "<<A[i].min_galinis<<endl;	
		}
		else fr<<i+1<<" "<<A[i].h_galinis<<" "<<A[i].min_galinis<<endl;
    }
    
    fd.close();
    fr.close();
    return 0;
}


