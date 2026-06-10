#include<iostream>
#include<fstream>
using namespace std;
void skaiciavimas (int n, int & val, int & min, int & vi , int & si ){
	double laikas;
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	fd>>val>>min>>n;
	for(int i=0;i<n;i++){
	fd>>si>>vi;
	laikas=(double)si/vi*60;

	val=(laikas+val*60+min)/60;
	min=(laikas+val*60+min)-(val*60);
	for(int j=0;j<3;j++){
		if(min>=60) min-=60;
		else break;
	}
	for(int c=0;c<2;c++){
		if(val>=24) val-=24;
		else break;
	}
	fr<<(i+1)<<" "<<val<<" "<<min<<endl;
	
	
}
	
	
	fd.close();
	fr.close();
}





int main() {
	int n,si,vi,val,min;
skaiciavimas(n,val,min,vi,si);



return 0;
}

