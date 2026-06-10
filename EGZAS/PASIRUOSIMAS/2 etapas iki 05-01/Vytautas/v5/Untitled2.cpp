#include<iostream>
#include<fstream>
using namespace std;
void grikiai( int n, double angl, double balt, double rieb,  int kiekis){
ifstream fd("duom.txt");
ofstream fr("rez.txt");
double reikia;
int dienos =0;
fd>>n>>angl>>balt>>rieb;
reikia=(1800/349)*100;
for(int i=0;i<n;i++){
	fd>>kiekis;
	fr<<(double)kiekis*angl/100<<" "<<(double)kiekis*balt/100<<" "<<(double)kiekis*rieb/100<<endl;
	if(kiekis>=reikia) dienos++;
	
}	
	fr<<"Vaida suvartojo reikiama kaloriju kieki "<<dienos<<" dienas";
	
	
fd.close();
fr.close();	
}



int main() {
int n,kiekis;
double angl,balt,rieb;
grikiai(n,angl,balt,rieb,kiekis);



return 0;
}

