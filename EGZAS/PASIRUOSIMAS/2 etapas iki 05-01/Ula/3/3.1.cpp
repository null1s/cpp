#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

void kelione(int n, int a, int b, int x, int y, int z, double & n_kaina, double & a_kaina, double & b_kaina, double & visu_kaina, double & n4_kaina)
{
	if (n<10)
	{
		n_kaina=n*x;
		a_kaina=a*x;
		b_kaina=b*x;
	}
	else if (n<20)
	{
		n_kaina=n*y;
		a_kaina=a*y;
		b_kaina=b*y;
	}
	else if (n<31)
	{
		n_kaina=n*z;
		a_kaina=a*z;
		b_kaina=b*z;
	}
	
	if (n+4<10)	n4_kaina=(n+4)*x;
	else if (n+4<20) n4_kaina=(n+4)*y;
	else if (n+4<31) n4_kaina=(n+4)*z;
	visu_kaina=n4_kaina/n;
}

int main ()
{
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
	
	int n, a, b, x, y, z;
	double n_kaina, a_kaina, b_kaina, visu_kaina, n4_kaina;
	fd>>n>>a>>b>>x>>y>>z;
	
	kelione(n,a,b,x,y,z,n_kaina,a_kaina,b_kaina,visu_kaina,n4_kaina);
	fr<<fixed<<setprecision(2)<<n_kaina<<" "<<a_kaina<<" "<<b_kaina<<endl;
	fr<<fixed<<setprecision(2)<<n4_kaina<<endl;
	fr<<fixed<<setprecision(2)<<visu_kaina;	
	
    fd.close();
    fr.close();
return 0;
}




