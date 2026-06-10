#include<iostream>
#include<fstream>
using namespace std;
int main() {
int n,m,vieta,bendrakaina=0,bendraskiekis=0;
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>n>>m;
for (int i = 0; i<n; i++){
	
	for (int j=0; j<m; j++){
		fd>>vieta;
		if( (i==1 || i==2 ) && vieta == 1) {
			bendrakaina +=100;
			bendraskiekis++;
		}
		else if( (i==3 || i==4 ) && vieta == 1) {
			bendrakaina +=70;
			bendraskiekis++;
		}
		else if( vieta == 1) {
			bendrakaina +=40;
			bendraskiekis++;
		}
		
	}
}
fr<<bendrakaina<<" "<<(double)bendrakaina/bendraskiekis;



fd.close();
fr.close();

return 0;
}

