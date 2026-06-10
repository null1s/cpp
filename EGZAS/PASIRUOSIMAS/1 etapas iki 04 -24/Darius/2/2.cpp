#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
int n, d=0, lk, k=0, k1=0;
ifstream fd ("duom.txt");
ofstream fr ("rez.txt");
fd>>n;
for(int i=0; i<n; i++){
	fd>>d;
	for(int j=0; j<d; j++){
	fd>>lk;
	k=k+lk;
}
fr<<k<<endl;
k1+=k;
k=0;
}
fr<<k1<<endl;
fd.close();
fr.close();


}

