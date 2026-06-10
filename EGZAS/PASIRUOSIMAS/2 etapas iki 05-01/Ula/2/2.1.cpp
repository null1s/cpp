#include<fstream>
#include<iostream>
using namespace std;

void numeriai(int n, int m, int & sk)
{
	while (n<m)
	{
		if (n/100==n%10) sk++;
		n++;
	}
}

int main ()
{
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
	
	int n, m, sk=0;
	fd>>n>>m;
	
	numeriai(n,m,sk);
	fr<<sk;
	
    fd.close();
    fr.close();
return 0;
}




