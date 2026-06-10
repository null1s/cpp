#include<fstream>
#include<iostream>

using namespace std;

void skaityti(int &n1, int &n2, int &x, int A[]) {
	ifstream fd("duom.txt");
	
	fd >> n1 >> n2 >> x;
	for (int i=0; i<x; i++) {
		fd >> A[i];
	}
	
	fd.close();
}

void spausdinti() {
	ofstream fr("rez.txt");
	
	
	fr.close();
}

void skaiciuoti(int n1, int n2, int x, int A[], 
				int &p1, int &p2, int &k, int &last) {
	for (int i=0; i<x; i++) {
		int kiekis = A[i];
		bool testi = true;
		while (testi
			&& kiekis > 0 
			&& kiekis % 2 == 0 
			&& n2 > 0) {
			// atimam maisus po 2kg
			kiekis -= 2;
			n2 -= 1;
			p2 += 1;
			cout << "[p2+1] parduotas 2 kg" << endl;
		}
		
		while (testi && kiekis > 0 && n1 > 0) {
			// atimam maisus po 1kg
			kiekis -= 1;
			n1 -= 1;
			p1 += 1;
			cout << "[p1+1] parduotas 1 kg" << endl;
		}
	}
}


int main() {
	int n1, n2, x, A[100];
	int p1 = 0, p2 = 0; // parduoda 1kg ir 2 kg
	int k = 0, last = 0;
	
	skaityti(n1, n2, x, A);
	skaiciuoti(n1, n2, x, A, p1, p2, k, last);
	
	cout << p1 << " " << p2 << endl;
	
	
	return 0;
}
