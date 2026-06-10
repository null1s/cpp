#include<iostream>
#include<fstream>
using namespace std;
int main() {
int n,dienine,visu=0,o,m;
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>n;
for(int i=0;i<n;i++){
	fd>>m;
	
	for(int j=0;j<m;j++){
		fd>>o;
		dienine+=o;
	}
	fr<<dienine<<endl;
	visu+=dienine;
	dienine=0;
	
}
fr<<visu;
fd.close();
fr.close();

return 0;
}

