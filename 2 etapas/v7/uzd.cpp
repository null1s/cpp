#include<iostream>
#include<fstream>
using namespace std;

struct Trupmena {
	int sv = 0;
	int sk = 0;
	int vd = 0;
	
	int osv = sv;
	int osk = sk;
	int ovd = vd;
	
	bool neig = false;
};

int dbd(int a, int b) {
	// Euklido algoritmas
	while (abs(a) && abs(b))
		if (abs(a) > abs(b)) a %= b; 
	    else b %= a;
	return a + b;
}

void prastinti(Trupmena &X) {
	if (X.sk < 0) {
		X.sk *= -1;
		X.neig = true;
	}
	
	while (X.sk - X.vd > 0) {
		X.sv++;
		X.sk -= X.vd;
	}
	
	int daliklis = dbd(X.sk, X.vd);
	X.sk = X.sk / daliklis;
	X.vd = X.vd / daliklis;
	if (X.sk == 1 && X.vd == 1) {
		X.sv++;
		X.sk = 0;
		X.vd = 0;
	}
}

void suma(Trupmena A, Trupmena B, Trupmena &C) {
	if (A.sv > 0) {
		A.sk += A.vd * A.sv;
		A.sv = 0;
	}
	if (B.sv > 0) {
		B.sk += B.vd * B.sv;
		B.sv = 0;
	}
	
	C.sv = 0; 
	C.sk = A.sk * B.vd + B.sk * A.vd;
	C.vd = A.vd * B.vd;
	
	prastinti(C);
}
void skirtumas(Trupmena A, Trupmena B, Trupmena &D) {
	if (A.sv > 0) {
		A.sk += A.vd * A.sv;
		A.sv = 0;
	}
	if (B.sv > 0) {
		B.sk += B.vd * B.sv;
		B.sv = 0;
	}
	
	D.sv = 0; 
	D.sk = A.sk * B.vd - B.sk * A.vd;
	D.vd = A.vd * B.vd;
	
	prastinti(D);
}

void isvesti(ofstream &fr, Trupmena A, Trupmena B, Trupmena C, Trupmena D) {
	fr << "      ";
	if (A.sv > 0) fr << A.sv << " ";
	else fr << "  ";
	fr << A.sk << "/" << A.vd << "      ";
	
	
	fr << "      ";
	if (B.sv > 0) fr << B.sv << " ";
	else fr << "  ";
	fr << B.sk << "/" << B.vd << "      ";
	
	fr << "      "; // Suma
	if (C.sv > 0 && C.neig) fr << "-";
	if (C.sv > 0) fr << C.sv << " ";
	if (C.sv <= 0 && C.neig) fr << "-";
	if (C.sk > 0 && C.vd > 0) {
		fr << C.sk;
		fr << "/";
		fr << C.vd;
	}
	fr << "      "; 
	
	fr << "      "; // Skirtumas
	if (D.sv > 0 && D.neig) fr << "-";
	if (D.sv > 0) fr << D.sv << " ";
	if (D.sv <= 0 && D.neig) fr << "-";
	if (D.sk > 0 && D.vd > 0) {
		fr << D.sk;
		fr << "/";
		fr << D.vd;
	}
	fr << endl << endl;
}

int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt", ios_base::app);

    int n;
    fd >> n;
    
    Trupmena A[20]; // T1
    Trupmena B[20]; // T2
    Trupmena C[20]; // Suma
    Trupmena D[20]; // Skirtumas
    
    for (int i=0; i<n; i++) {
    	fd >> A[i].sv >> A[i].sk >> A[i].vd;
    	fd >> B[i].sv >> B[i].sk >> B[i].vd;
	}
		
	fr << "---------------------------------------------------------------------" << endl;
	fr << "|       T1       |       T2       |      Suma      |    Skirtumas   |" << endl;
	fr << "---------------------------------------------------------------------" << endl;
	
    for (int i=0; i<n; i++) {
    	suma(A[i], B[i], C[i]);
    	skirtumas(A[i], B[i], D[i]);
    	isvesti(fr, A[i], B[i], C[i], D[i]);
	}
    
    fd.close();
    fr.close();
    return 0;
}

