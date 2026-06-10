#include<iostream>
#include<fstream>
using namespace std;
struct temperatura {
	string diena;
	int temp;
};
void skaitymas ( int & n , temperatura A[], int D1[], int D2[], int D3[], int D4[], int D5[]){
	ifstream fd("Temp.txt");
	int a=0,a2=0,a3=0,a4=0,a5=0,k=0,k2=0,k3=0,k4=0,k5=0;
	fd>>n;
	for ( int i =0; i<n; i++){
		fd>>A[i].diena>>A[i].temp;
	}
	while(  k<n){
		if(A[k].diena = "Pirmadienis" ){
			D1[a]=A[i].temp;
			a++;
		}
		k++;
	} 
	while(  k2<n){
		if(A[k2].diena = "Antradienis" ){
			D2[a2]=A[k2].temp;
			a2++;
		}
		k2++;
	} 
	while(  k3<n){
		if(A[k3].diena = "Treciadienis" ){
			D3[a3]=A[k3].temp;
			a3++;
		}
		k3++;
	} 
	while(  k4<n){
		if(A[k4].diena = "Ketvirtadienis" ){
			D4[a4]=A[k4].temp;
			a4++;
		}
		k4++;
	} 
	while(  k5<n){
		if(A[k5].diena = "Penktadienis" ){
			D5[a5]=A[k5].temp;
			a5++;
		}
		k5++;
	} 
	fd.close();
}
void rikiavimas ( int & n, int D1[], int D2[], int D3[], int D4[], int D5[]){
	
	
	
	
	
	
}



void israsas (int & n , A){
	ofstream fr("rez.txt");
	
	
	
	
	fr.close();
}




int main() {
int	n, D1[24],D2[24],D3[24],D4[24],D5[24];
temperatura A[168];
skaitymas(n,A,D1,D2,D3,D4,D5);
rikiavimas(n,D1,D2,D3,D4,D5);






return 0;
}

