#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
double n=0, lk=0, k=0, k1=0, kiek=0;
ifstream fd ("duom.txt");
ofstream fr ("rez.txt");
for(int j=0; j<6; j++){
fd>>n;
	for(int j=0; j<n; j++){
	fd>>lk;
	k1+=lk;
}
}
fd>>kiek;
fr<<k1<<endl;
if (k1>=kiek) fr<<"uzteks";
else fr<<"neuzteks";

fd.close();
fr.close();


}

