#include<iostream>
#include<fstream>
using namespace std;

void skaiciavimas(int n, int A[], double meta[], double &a, double &b, double &r) {
    ofstream fr("rez.txt", ios_base::app);
	for (int i=0; i<n; i++) {
		a = A[i] * (meta[0] / 100);
		b = A[i] * (meta[1] / 100);
		r = A[i] * (meta[2] / 100);
		fr << a << " " << b << " " << r << endl;
	}
	fr.close();
}
int kiekis(int n, int A[]) {
	int dienos = 0;
	for (int i=0; i<n; i++) {
		// 100g -> 349 kcal
		// 1g -> 3.49 kcal
		if (A[i] * 3.49 > 1800) dienos++;
	}
	return dienos;
}

int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt", ios_base::app);

    int n, x, A[20];
    fd >> n;
    
    double meta[3];
    for (int i=0; i<3; i++) fd >> meta[i];
    // 0 - angliavandeniai
    // 1 - baltymai
    // 2 - riebalai
    
    for (int i=0; i<n; i++) fd >> A[i];
    
	double a, b, r;
	skaiciavimas(n, A, meta, a, b, r);
	
	int dienos = kiekis(n, A);
	fr << "Vaida suvartojo reikiama kaloriju kieki " << dienos << " dienas";
    
    fd.close();
    fr.close();
    return 0;
}

