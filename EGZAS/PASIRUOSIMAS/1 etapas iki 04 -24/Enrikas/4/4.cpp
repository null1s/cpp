#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fd("duom4.txt");
	ofstream fr("rez4.txt");
	
	int n;
	fd>>n;
	
	int nr, balas;
	
	int pirm[100], antr[100], trec[100];
	int p=0, a=0, t=0;
	
	for(int i=0; i<n; i++){
		fd>>nr>>balas;
		
		if(balas >=1 && balas<=3){
			pirm[p++]=nr;
		} else if (balas>=4&&balas<=6){
			antr[a++]=nr;
		} else if (balas>=7&&balas<=10){
			trec[t++]=nr;
		}
	}
	fr<<"Pirmasis: ";
	for (int i=0; i<p; i++){
		fr<<pirm[i]<<" ";
	}
	fr<<endl;
	
	fr<<"Antrasis: ";
	for(int i=0; i<a; i++){
		fr<<antr[i]<<" ";
	}
	fr<<endl;
	
	fr<<"Treciasis: ";
	for(int i=0; i<t; i++){
		fr<<trec[i]<<" ";
	}
	fr<<endl;
	
	fd.close();
	fr.close();
	
	return 0;
}
