#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int kaina(int eile) {
	if (eile == 1 || eile == 2) return 100;
	if (eile == 3 || eile == 4) return 70;
	else return 40;
}

void skaiciavimas(double &pelnas, double &vidurkis) {	
	ifstream fd("duom.txt");
	int eiles, vietos, x, y;
	fd >> eiles >> vietos;
	
	for (int eile=0; eile<eiles; eile++) {
		for (int vieta=0; vieta<vietos; vieta++) {
			fd >> x;
			if (x) {
				pelnas += kaina(eile + 1);
				y++;
			}	
		}
	}
	vidurkis = pelnas / y;
	fd.close();
}

int main() {
	ofstream fr("rez.txt");

	double pelnas = 0, vidurkis = 0;
	skaiciavimas(pelnas, vidurkis);
	fr << pelnas << " " << fixed << setprecision(2) << vidurkis;
	
	fr.close();
	return 0;
}

