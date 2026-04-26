#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int apversti(int i) {
	string s = to_string(i);
    reverse(s.begin(), s.end());
    return stoi(s);
}

int main() {
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");

	int n, m, k = 0;
	fd >> n >> m;
	
	for (int i=n; i<=m; i++) {
		if (i == apversti(i)) k++;
	}
	
	fr << k;

	fd.close();
	fr.close();
	return 0;
}

