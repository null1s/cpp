#include<iostream>
#include<fstream>
using namespace std;

struct Dienos {
	int pi;
	int an;
	int tr;
};

struct Rez {
	int valandos = 0;
	int virsijo = 0;
	int truko = 0;
};

void skaiciavimas(int n, Dienos A[], int meta[], Rez B[], Rez &Bendras) {
	for (int i=0; i<n; i++) {
		B[i].valandos = A[i].pi + A[i].an + A[i].tr;

		// pi
		if (A[i].pi > meta[0]) B[i].virsijo++;
		if (A[i].pi < meta[0]) B[i].truko++;
		
		// an
		if (A[i].an > meta[1]) B[i].virsijo++;
		if (A[i].an < meta[1]) B[i].truko++;
		
		// tr
		if (A[i].tr > meta[2]) B[i].virsijo++;
		if (A[i].tr < meta[2]) B[i].truko++;
		
		Bendras.valandos += B[i].valandos;
		Bendras.virsijo += B[i].virsijo;
		Bendras.truko += B[i].truko;
	}
}

void isvesti(Rez B) {
	ofstream fr("rez.txt", ios_base::app);
	
	fr << B.valandos << " " << B.virsijo << " " << B.truko << endl;
	
	fr.close();
}

int main() {
    ifstream fd("duom.txt");

    int n, x;
    fd >> n;
    
    int meta[3] = {5, 6, 4};
    // 0 - pirmadienis (5)
    // 1 - antradienis (6)
    // 2 - treciadienis (4)
    
    Dienos A[20];
    for (int i=0; i<n; i++) fd >> A[i].pi >> A[i].an >> A[i].tr;
    
    Rez B[20];
    Rez Bendras;
    
	skaiciavimas(n, A, meta, B, Bendras);
	
	for (int i=0; i<n; i++) isvesti(B[i]);
	isvesti(Bendras);
    
    fd.close();
    return 0;
}

// Uzduotyje pateikti klaidingi rezultatai!
// ----------------------------
// pi: 3 virsijo | 0 truko;
// an: 2 virsijo | 1 truko;
// tr: 3 virsijo | 0 truko;
// ----------------------------
// 1 sav:  + - + ;
// 2 sav:  + + + ;
// 3 sav:  ? ? + ;
// 4 sav:  + + ? ;
