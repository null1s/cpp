#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
int n=0, d=0, lk=0, k=0, k1=0, s=0, temp=0;
ifstream fd ("duom1.txt");
ofstream fr ("rez.txt");
fd>>n;
for(int i=0; i<n; i++){
	fd>>d;
	for(int j=0; j<d; j++){
	if (s==1) fd>>temp;	
	if (j==0) s=0;
	if (s==0){
	fd>>lk;
	k+=lk;
	if ((k%2)==0) s=1;
}
	temp=0;
	cout<<k<<endl;
}
fr<<k<<endl;
k=0;
}
fd.close();
fr.close();


}

