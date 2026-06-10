#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main() {
long long int n;
string nr;
long long int A[16];
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>nr;
fd>>n;
int a=1;
cout<<nr<<" "<<n<<" "<<endl;
int i =1;
while ( i != 0){
	if((n/pow(10,a))>1) a++;
	else i=0;

}
cout<<a<<endl;
int akop=a;
for(int j=1;j<=a;j++){
 A[j]=n/pow(10,akop);
 akop--;
	cout<<A[j]<<endl;
	
	
	
}
fd.close();
fr.close();

return 0;
}

