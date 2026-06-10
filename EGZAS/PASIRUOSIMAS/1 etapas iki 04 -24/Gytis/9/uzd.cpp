#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	
	int n, m;
	fd >> n >> m;
	
	int kiekis = 0;
	int maxKiekis = 0;
	int maxId = 0;

	for (int i=n; i<=m; i++) {
		for (int j=1; j<=i; j++) {
			if (i % j == 0) kiekis++;	
		}
		if (kiekis > maxKiekis) {
			maxKiekis = kiekis;
			maxId = i;
		}
		kiekis = 0;
	}
	
	fr << "Skaicius " << maxId << " turi daugiausia dalikliu " << maxKiekis << endl;
	for (int i=1; i<=maxId; i++) {
		if (maxId % i == 0) fr << i << " ";
	}

	fd.close();
	fr.close();
	return 0;
}
