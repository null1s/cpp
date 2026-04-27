#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	int a, b;
	
	fd >> a >> b;
	fr << "Skaicius | Dalijasi is:" << endl;
	for (int i=a; i<=b; i++) {
		int x = 2, c = 0;
		while (x < i) {
			if (i % x == 0) c++;
			x++;
		}
		fr << i << "               " << c << endl;
	}

	
	fd.close();
	fr.close();
	return 0;
}
