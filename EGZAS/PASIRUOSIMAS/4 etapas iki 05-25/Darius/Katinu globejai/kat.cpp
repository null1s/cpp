#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
int n, eur[20], cent[20], sk1, k1, sk2, k2, bendr[20], max, maxp, k;
string vard[20];
ifstream fd ("duom.txt");
ofstream fr ("rez.txt");
fd>>n;
for(int i=0; i<n; i++){
	fd>>vard[i]>>eur[i]>>cent[i]>>k>>sk1>>k1>>sk2>>k2;
	bendr[i]=(eur[i]*100+cent[i])-(sk1*k1+sk2*k2);
	eur[i]=bendr[i]/100;
	cent[i]=bendr[i]-bendr[i]/100*100;
}
for(int i=0; i<n; i++){
	fr<<vard[i]<<" "<<eur[i]<<" "<<cent[i];
	
}
fd.close();
fr.close();


return 0;
}

