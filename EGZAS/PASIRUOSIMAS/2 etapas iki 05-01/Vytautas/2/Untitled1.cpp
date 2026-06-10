#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int sukti( int i ){
	int sk=0;
	while( i > 0){
		sk=sk*10+i%10;
		i/=10;
		
		
	}
	
	
	return sk;
}



int main() {
	int n,m,a=0,teisingai=0;
	ifstream fd("duom.txt");
ofstream fr("rez.txt");

fd>>n>>m;
for(int i=n;i<=m;i++){
 if( i == sukti(i) )teisingai++;
	
	
	cout<<"i= "<<i<<" sukti (i) ="<<sukti(i)<<endl;
}
fr<<teisingai;






fd.close();
fr.close();

return 0;
}

