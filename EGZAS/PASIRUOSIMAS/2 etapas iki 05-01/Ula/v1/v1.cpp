#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

struct vietos
{
	int viet[100];
};

void vietos_kaina (vietos A[], int & kain, int i, int j)
{
	if ((i>=0 && i<=1) && A[i].viet[j]==1) kain+=100;
	else if ((i>=2 && i<=3) && A[i].viet[j]==1) kain+=70;
	else if (A[i].viet[j]==1) kain+=40;
}

void kaina (vietos A[], int kain, int & bendra, double & vid, int eil, int vt)
{
	int sk=0;
	
	for (int i=0; i<eil; i++)
	{
		for (int j=0; j<vt; j++)
		{
			if (A[i].viet[j]==1) sk++; 
			vietos_kaina(A,kain,i,j);
			bendra=bendra+kain;
			kain=0;	
		}
	}
	vid=(double)bendra/sk;
}

int main ()
{
    vietos A [100];
    
	ifstream fd("duom.txt");
    ofstream fr("rez.txt");

    int eil, vt, kain, bendra=0;
    double vid;
    fd>>eil>>vt;
    
    for (int i=0; i<eil; i++)
    {
    	for (int j=0; j<vt; j++)
    	{
    		fd>>A[i].viet[j];
		}
	}
	
/*/	for (int i=0; i<eil; i++)
	{
		for (int j=0; j<vt; j++)
		{
			vietos_kaina(A,kain,i,j);
			kain=0;
		}
	}/*/
	kain=0;
	kaina(A,kain,bendra,vid,eil,vt);

	fr<<fixed<<setprecision(2)<<bendra<<" "<<vid;
	
    fd.close();
    fr.close();
    return 0;
}




