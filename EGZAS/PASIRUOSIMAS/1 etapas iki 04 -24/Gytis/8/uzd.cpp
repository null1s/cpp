#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
	
	int n, m, x, A[20] = {0};
	fd >> n;
	
	for (int i=0; i<n; i++) {
		fd >> m;
		bool skip = false;
		for (int j=0; j<m; j++) {
			fd >> x;
			if (!skip) A[i] += x;
			if (x % 2 == 0) skip = true;
		}
	}
	
	for (int i=0; i<n; i++) {
		fr << i+1 << " - Zaidejas surinko " << A[i] << " tasku" << endl;
	}
	
	int maxId = 0;
    for (int i=1; i<n; i++) {
        if (A[i] > A[maxId]) {
            maxId = i;
        }
    }
    
    fr << "Zaidima laimejo " << maxId+1 << " zaidejas, jis surinko " << A[maxId] << " tasku";

	fd.close();
	fr.close();
	return 0;
}
