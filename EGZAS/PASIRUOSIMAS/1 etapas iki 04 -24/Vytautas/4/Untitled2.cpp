#include<iostream>
#include<fstream>
using namespace std;
struct mokinys{
	int numeris;
	int balas;
	int identifikatorius;
};
int main() {
int n;
mokinys A[50];
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>n;
for(int i = 0; i < n; i++){
	fd>>A[i].numeris>>A[i].balas;
}
int j=0;
while(j<n){
	if(A[j].balas>=7) A[j].identifikatorius=3;
	else if (A[j].balas<=3) A[j].identifikatorius=1;
	else A[j].identifikatorius=2;
	j++;
}
fr<<"Pirmasis: ";
for(int a=0;a<n;a++){
	if(A[a].identifikatorius==1) fr<<A[a].numeris<<" ";
}
fr<<endl<<"Antrasis: ";
for(int b=0;b<n;b++){
	if(A[b].identifikatorius==2) fr<<A[b].numeris<<" ";
}
fr<<endl<<"Treciasis: ";
for(int c=0;c<n;c++){
	if(A[c].identifikatorius==3) fr<<A[c].numeris<<" ";
}
fd.close();
fr.close();

return 0;
}

