#include<iostream>
#include<fstream>

using namespace std;

struct max {
	int id;
	int sum;
};

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	
	int n;
	fd >> n;
	
	int sums[5] = {0};
	
	for (int i=0; i<n; i++) {
		int m, id;
		fd >> id >> m;
		
		for (int j=0; j<m; j++) {
			int x;
			fd >> x;
			if (id >= 1 && id <= 4) {
                sums[id] += x;
            }
		}
	}
	fr << "Pjaustykliu: " << sums[1] << " Eur" << endl;
	fr << "Virduliu: " << sums[2] << " Eur" << endl;
	fr << "Mikseriu: " << sums[3] << " Eur" << endl;
	fr << "Plaktuvu: " << sums[4] << " Eur" << endl;
	
	int maxId = 1;
    for (int i = 2; i <= 4; i++) {
        if (sums[i] > sums[maxId]) {
            maxId = i;
        }
    }

    string names[5] = {"", "Pjaustykliu", "Virduliu", "Mikseriu", "Plaktuvu"};
    fr << names[maxId] << " pagaminta didziausiai sumai";
    
	fd.close();
	fr.close();
	return 0;
}
