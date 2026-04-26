#include<iostream>
#include<fstream>
using namespace std;

void skaiciavimas(int i, int oval, int omin, int si, int vi, int &nval, int &nmin) {	
	// oval:omin - dabartinis laikas
	// nval:nmin - atvykimo laikas
	// si - atstumas; vi - greitis
	// s = v * t => t = s/v
	int laikas = (si * 60) / vi; // min
	
	nmin = omin + laikas;
	while (nmin >= 60) {
		nmin -= 60;
		nval++;
	}
	while (nval >= 24) nval -= 24;
	
	ofstream fr("rez.txt", std::ios_base::app);
	fr << i+1 << " " << nval << " " << nmin << endl;
	fr.close();
}

int main() {
	ifstream fd("duom.txt");
	
	int val, min, n;
	fd >> val >> min >> n;
	
	int si, vi, oval = val, omin = min, nval = val, nmin = min;
	for (int i=0; i<n; i++) {
		fd >> si >> vi;
		skaiciavimas(i, oval, omin, si, vi, nval, nmin);
		oval = nval; // atnaujinam sena val
		omin = nmin; // atnaujinam sena min
	}
	
	fd.close();
	return 0;
}

