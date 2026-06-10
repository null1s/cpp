#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
int main ( ){
	int a,b=0;
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	

while (fd>>a) {
 
 if (a==33 || a==34 || a==44 || a==46 || (a>=48 && a<=57) || a==63 || (a>=65 && a<=90)  || (a>=97 && a<=122) ){
 cout<<" ";
 }
 else {
 	b=INT_MAX;
 	break;
 }
}
		if(b==INT_MAX) fr<< " Teisingai";
		else fr<<"Neteisingas simbolis";

	fd.close();
	fr.close();
	
return 0;	
}

