#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;

struct coord {
	int x;
	int y;
	double d;
};

double ilgis(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double plotas(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");

	coord A[20] = {0};
	int n = 3;
	
	for (int i=0; i<n; i++) {
		fd >> A[i].x >> A[i].y;
	}
	
	// a - A ir B (0 ir 1)
	// b - B ir C (1 ir 2)
	// c - C ir A (2 ir 0)
	A[0].d = ilgis(A[0].x, A[0].y, A[1].x, A[1].y);
	A[1].d = ilgis(A[1].x, A[1].y, A[2].x, A[2].y);
	A[2].d = ilgis(A[2].x, A[2].y, A[0].x, A[0].y);
	
	fr << fixed << setprecision(2);
	fr << plotas(A[0].d, A[1].d, A[2].d);

	fd.close();
	fr.close();
	return 0;
}

