#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");

	int sim, kl = 0;
	
	while (!fd.eof()) {
		fd >> sim;
		if (sim < 32 || sim > 122) kl++;
		else if (sim > 33 && sim < 44) kl++;
		else if (sim == 45 || sim == 47) kl++;
		else if (sim > 57 && sim < 63) kl++;
		else if (sim == 64) kl++;
		else if (sim > 90 && sim < 97) kl++;
	}
	
	if (kl == 0) fr << "Teisingai";
	else for (int i=0; i<kl; i++) fr << "Neteisingas simbolis" << endl;
	// ar nori rytoj susitikti kieme 15h?
	
	fd.close();
	fr.close();
	return 0;
}

