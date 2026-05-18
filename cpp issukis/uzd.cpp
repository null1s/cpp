#include<fstream>
#include<iostream>

using namespace std;

struct diena {
	string d;
	int x;
	int t;
};

int main() {
	ifstream fd("duom.txt");
	diena A[24*7];
	int B[7][25];
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
	
	for (int i=0; i<n; i++) {
		int z = 1;
		for (int j=0; j<5; j++) {
			if (A[i].x == j) {
				B[j][z] = A[i].t;
				B[j][0] = z;
				z++;
			}
		}
	}
	for (int i=0; i<B[0][0]; i++) {
		cout << B[0][i] << " ";
	}

	
	fd.close();
}

// Pi: 2, -1, 2, -1, 2, -1, 8, -11, 9, -11, 0, 8
// An: -5, 6, -5, 4, 2, 6
// Tr: 6, 6, 2
// Ke: 8, -2, 8
// Pn: 9
