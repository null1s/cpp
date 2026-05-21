#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;

struct diena {
	string d;
	int x;
	int t;
};

double average(int B[]) {
	int sum = 0;
	for (int i=1; i<=B[0]; i++) {
		sum += B[i];
	}
	return (double)sum / B[0];
}

bool pirminis(int x) {
	if (x <= 0) return false; // neigiami skaiciai ir 0 nebuna pirminiai
	int k = 2; // vienetas ir pats
	for (int i=2; i<x; i++) {
		if (x % i == 0) k++;
	}
	return k > 2;
	
}

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	diena A[24*7];
	int B[7][25] = {0};
	int n;
	
	fd >> n;
	
	for (int i=0; i<n; i++) {
		fd >> A[i].d >> A[i].t;
		if (A[i].d == "Pirmadienis") A[i].x = 0;
		if (A[i].d == "Antradienis") A[i].x = 1;
		if (A[i].d == "Treciadienis") A[i].x = 2;
		if (A[i].d == "Ketvirtadienis") A[i].x = 3;
		if (A[i].d == "Penktadienis") A[i].x = 4;
	}
	
	// 0/1/2/3/4 - savaites diena
	for (int j=0; j<5; j++) { 
		int z = 1;
		for (int i=0; i<n; i++) { 
			if (A[i].x == j) { 
				B[j][z] = A[i].t; 
				B[j][0] = z;
				z++;
			}
		}
	}
	
	
	// rusiavimas didejimo tvarka
	for (int j=0; j<5; j++) {
		for (int p=1; p<=B[j][0]; p++) {
            for (int i=1; i<=B[j][0]-p; i++) {
                if (B[j][i] > B[j][i+1]) {
                    int temp = B[j][i];
                    B[j][i] = B[j][i+1];
                    B[j][i+1] = temp;
                }
            }
        }
	}
	
	for (int j=0; j<5; j++) {
		for (int i=1; i<=B[j][0]; i++) {
			fr << B[j][i] << " ";
		}
		fr << endl;
	}
	fr << "-----------------------" << endl;
	
	
	// vidutine temperatura
	for (int j=0; j<5; j++) {
		fr << fixed << setprecision(2) << average(B[j]) << endl;
	}
	fr << "-----------------------" << endl;
	
	
	// pasalinti pirminius skaicius
	for (int j=0; j<5; j++) {
		for (int i=1; i<=B[j][0]; i++) {
			if (pirminis(B[j][i])) {
				for (int y=i; y<B[j][0]; y++) {
					B[j][y] = B[j][y+1];
				}
				i--;
				B[j][0]--;
			}
		}
	}
	for (int j=0; j<5; j++) {
		for (int i=1; i<=B[j][0]; i++) {
			fr << B[j][i] << " ";
		}
		fr << endl;
	}
	fr << "-----------------------" << endl;
	
	// dregmes iterpimas
	// ???
	
	
	fd.close();
	fr.close();
}
