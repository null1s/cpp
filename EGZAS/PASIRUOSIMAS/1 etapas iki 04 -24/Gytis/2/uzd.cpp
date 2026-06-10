#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	
	int n, bendras = 0;
	fd >> n;
	
	for (int i=0; i<n; i++) {
		int m, t, suma = 0;
		fd >> m;
		for (int j=0; j<m; j++) {
			fd >> t;
			suma += t;
		}
		fr << suma << endl;
		bendras += suma;
	}
	fr << bendras;
	
	fd.close();
	fr.close();
	return 0;
}
