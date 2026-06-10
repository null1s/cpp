#include<iostream>
#include<fstream>
using namespace std;
int main() {
double n,m,pinigai,pinigaireikia,taupo;
ifstream fd("duom.txt");
ofstream fr("rez.txt");
n=6;
for(int i=0;i<n;i++){
	fd>>m;
	for(int j=0;j<m;j++){
		fd>>taupo;
		cout<<"taupo "<<taupo<<endl;
		pinigai+=taupo;
		cout<<"Pinigai = "<<pinigai<<endl;
	}
}
fd>>pinigaireikia;
fr<<pinigai<<endl;
if(pinigai>=pinigaireikia) fr<<"Nusipirks";
else fr<<"Truksta finansiniu galimybiu";
fd.close();
fr.close();

return 0;
}

