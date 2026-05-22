#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;
int main() {
	int sk = 0;
	string line;
	
	ifstream fd("dreg.csv");
	
    while(getline(fd,line)) sk++;
	fd.clear();
	fd.seekg(0);
	
	for (int i=0; i<sk; i++) {
		string diena;
		int dregme;
		
		getline(fd,line);
		stringstream ss(line);
		
		getline(ss, diena, ';');
		ss >> dregme;
		ss.ignore();
		
		cout << diena << " " << dregme << endl;
	}
	
	
	cout << endl<<endl<<endl;
	cout << 75254/1000;
	
	
	return 0;
}


