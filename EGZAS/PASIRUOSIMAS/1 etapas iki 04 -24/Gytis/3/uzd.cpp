#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	
	int x;
	double y, kaina, sum = 0;
	for (int i=0; i<6; i++) {
		fd >> x;
		for (int j=0; j<x; j++) {
			fd >> y;
			sum += y;
		}
	}
	fd >> kaina;
	
	fr << sum << endl;
	
	if (sum > kaina) fr << "Uzteks";
	else fr << "Neuzteks";
	
	fd.close();
	fr.close();
	return 0;
}
