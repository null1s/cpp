#include<iostream>
#include<fstream>

using namespace std;

struct mok {
	int kodas;
	int balas;
};

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	
	int n;
	fd >> n;
	
	mok A[20];
	
	for (int i=0; i<n; i++) {
		fd >> A[i].kodas >> A[i].balas;
	}
	
	fr << "Pirmasis: "; 
	for (int i=0; i<n; i++) {
		if (A[i].balas <= 3) fr << A[i].kodas << " ";
	}
	
	fr << endl << "Antrasis: "; 
	for (int i=0; i<n; i++) {
		if (A[i].balas > 3 && A[i].balas < 7) fr << A[i].kodas << " ";
	}
	
	fr << endl << "Treciasis: "; 
	for (int i=0; i<n; i++) {
		if (A[i].balas >= 7) fr << A[i].kodas << " ";
	}
	
	fd.close();
	fr.close();
	return 0;
}
