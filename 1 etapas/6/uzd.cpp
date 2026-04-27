#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	ifstream fd("duom.txt");
	
	while (!fd.eof()) {
		long long nr;
		int A[20];
		fd >> nr;
		
		// get len
		int n = 0;
		while (nr >= 0) {
			long long deg = pow(10, n);
			int skaicius = nr % (deg * 10) / deg;
			A[n] = skaicius;
			n++;
			
			if ((skaicius + 1) * deg > nr) break;	
		}
		
		// reverse
		for (int i=0; i<n/2; i++) {
			int x = A[i];
			A[i] = A[n-1-i];
			A[n-1-i] = x;
		}
		
		// luhn check
		int sum = 0;
		for (int i=0; i<n; i++) {
//			cout << A[i] << endl;
			int sk = A[i];
			if ((i+1) % 2 == 0) sk *= 2;// daugyba is 2
			
			if (sk >= 10 && sk < 100) { // dvizenklis
				int x = sk / 10;
				int y = sk % 10;
//				cout << x+y << endl;
				sum += x + y;
			}
			else sum += sk;
//			cout << "-------------" << endl;
		}
		cout << "sum: " << sum;
		
		cout << endl << "--------------------------------" << endl;
	}
	return 0;
}
//49927398716
//12121212
//1907039
//32165
//19
