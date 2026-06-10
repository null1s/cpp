#include<iostream>
#include<fstream>
#include<climits>
using namespace std;
int main() {
int n,m,A[50]= {0},B[50],a=0,numeris=0,b=0;
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>n>>m;

	for(int i=n; i<=m;i++){
	
		for(int j=1;j<=i;j++){
			
			if(i%j==0){
				A[i]++; 
				B[j]=j;
				cout<<" i = "<<i<<" j = "<<j<<" B[j] = "<<B[j]<<" i%j = "<<i%j<<"A[i] = "<<A[i]<<endl;
			} 
			a++;
			b++;
		}
	}
int maks=INT_MIN;
for(int c=n;c<=m;c++){
	if(A[c]>maks) { maks=A[c];
		numeris=c;
	}
	cout<<"A[c]= "<<A[c]<<" maks = "<<maks<<endl;
}
fr<<"Skaicius "<<B[numeris]<<" turi daugiausia dalikliu "<<maks<<endl;
for(int e=1;e<=m;e++){
if(B[numeris]%e==0)fr<<e<<" ";
}




fd.close();
fr.close();

return 0;
}

