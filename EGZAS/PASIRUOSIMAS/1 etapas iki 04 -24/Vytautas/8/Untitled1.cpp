#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

int main() {
int n,m,taskai,suma=0,A[20],sekiklis=0,numeris=0;
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>n;
for(int i = 0; i<n; i++){
	fd>>m;

	for(int j=0 ; j<m; j++){
		fd>>taskai;
	
		if(taskai%2==0 && sekiklis ==0) {
			suma+=taskai;
			sekiklis=1;
		
		}
		else if (sekiklis ==0 ) suma+=taskai;
		
			
	 taskai=0;
	}
	
	sekiklis=0;
	A[i]=suma;
	suma=0;
}
for(int c=1; c<=n; c++){
	fr<<c<<" - Zaidejas surinko "<<A[c-1]<<" taskus/u"<<endl;
}
int maks=INT_MIN;
for(int x=0;x<n;x++){
if(A[x]>maks) {
	maks=A[x];
	numeris=x;
}		
}
fr<<"Zaidima laimejo "<<numeris+1<<" zaidejas, surinkes "<<maks<<" tasku/us";

fd.close();
fr.close();

return 0;
}

