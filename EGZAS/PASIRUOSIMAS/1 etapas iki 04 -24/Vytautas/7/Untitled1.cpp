#include<iostream>
#include<fstream>
#include<climits>
using namespace std;
struct preke{
	int numeris=0;
	int kiekis=0;
	int kaina=0;
};
int main() {
int n,kai1=0,kai2=0,kai3=0,kai4=0;
preke A[50];
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>n;
int e=0;
for(int i = 0; i < n; i++){
	fd>>A[i].numeris>>A[i].kiekis;
	for(int j=0;j<A[i].kiekis;j++){
		fd>>e;
		A[i].kaina+=e;
	}
	if(A[i].numeris==1) kai1+=A[i].kaina;
	if(A[i].numeris==2) kai2+=A[i].kaina;
	if(A[i].numeris==3) kai3+=A[i].kaina;
	if(A[i].numeris==4) kai4+=A[i].kaina;
	A[i].kaina=0;
}
fr<<"Pjaustykliu: "<<kai1<<" Eur"<<endl;
fr<<"Virduliu: "<<kai2<<" Eur"<<endl;
fr<<"Mikseriu: "<<kai3<<" Eur"<<endl;
fr<<"Plaktuviu: "<<kai4<<" Eur"<<endl;
if(kai1>kai2 && kai1>kai3 && kai1>kai4) fr<<"Pjaustykliu buvo pagaminta uz didziausia suma ";
else if(kai2>kai1 && kai2>kai3 && kai2>kai4) fr<<"Virduliu buvo pagaminta uz didziausia suma ";
else if(kai3>kai1 && kai3>kai2 && kai3>kai4) fr<<"Mikseriu buvo pagaminta uz didziausia suma ";
else fr<<"Plaktuviu buvo pagaminta uz didziausia suma ";
fd.close();
fr.close();

return 0;
}

