#include<iostream>
#include<fstream>
#include<climits>
#include<iomanip>

using namespace std;

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	
	int n;
	double A[20];
	
	while (!fd.eof()) {
		fd >> A[n];
		n++;
	}
	
	double max_diff = INT_MIN;
	for (int i=0; i<n; i++) {
		fr << A[i] << endl;
		if (i+1 < n) {
			fr << "    (";
			double diff = A[i+1] - A[i];
			if (diff > max_diff) max_diff = diff;
			if (diff >= 0) fr << "+";
			fr << fixed << setprecision(1) << (double)diff << ")" << endl;
		}
	}
	fr << "---------------" << endl;
	fr << "Dienu skaicius: " << n << endl;
	fr << "Didziausias temperaturos pokytis: ";
	if (max_diff >= 0) fr << "+";
	fr << max_diff;
}


