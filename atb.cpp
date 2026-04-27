#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");

	int sk = 1578, atb = 0;
	
	while (sk > 0) {
		atb = atb * 10 + sk % 10;
		sk /= 10;
	}
	
	cout << atb;

	fd.close();
	fr.close();
	return 0;
}


