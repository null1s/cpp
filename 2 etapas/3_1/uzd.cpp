#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

double kelionesKaina(int n, int x, int y, int z) {
	int KAINA = y;
	if (n <= 10) KAINA = x;
	if (n >= 20) KAINA = z;
	
	return n * KAINA;
}

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");

	int n, a, b, x, y, z;
	fd >> n >> a >> b >> x >> y >> z;

	double visaKaina = kelionesKaina(n, x, y, z);
	double mokiniuKaina = kelionesKaina(n - b, x, y, z);
	double mokytojuKaina = visaKaina - mokiniuKaina;
	double vaikuKaina = kelionesKaina(n + 4, x, y, z);
	
	fr << fixed << setprecision(2);
	fr << visaKaina << " " << mokiniuKaina << " " << mokytojuKaina << endl;
	fr << vaikuKaina << endl;
	fr << vaikuKaina / n;  

	fd.close();
	fr.close();
	return 0;
}

