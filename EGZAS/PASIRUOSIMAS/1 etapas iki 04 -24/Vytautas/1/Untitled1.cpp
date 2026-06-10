#include<iostream>
#include<fstream>

using namespace std;
int main() {
int a,b,daliklis=0;
	ifstream fd("duom.txt");
	ofstream fr("rez.txt");
fd>>a>>b;
for(int i=a;i<=b;i++){
	daliklis=0;
	for(int j=2;j<i;j++){
		if( i % j==0) daliklis++;
		cout<<"i = "<<i<<" j = "<<j<<" i/j = "<<i/j<<" i%j ="<<i%j<<endl;
	}
	fr<<i<<" "<<daliklis<<endl;
}



fd.close();
fr.close();

return 0;
}

