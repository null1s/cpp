#include<iostream>
#include<fstream>
using namespace std;
int main() {
int n,a,b,x,y,z;
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>n>>a>>b>>x>>y>>z;
if(n<10){
	fr<<n*x<<" "<<a*x<<" "<<b*x<<endl;
	if ( n + 4 < 10){
		fr<<(double)(n+4)*x<<endl;
		fr<<(double)(n+4)*x/n;
	}
	else if ( n+4>=10 && n+4<19){
		fr<<(double)(n+4)*y<<endl;
		fr<<(double)(n+4)*y/n;
	}
	else {
		fr<<(double)(n+4)*z<<endl;
		fr<<(double)(n+4)*z/n;	
	}	
} 
else if (n < 19 && n >= 10){
	fr<<n*y<<" "<<a*y<<" "<<b*y<<endl;

	 if ( n+4>=10 && n+4<19){
		fr<<(double)(n+4)*y<<endl;
		fr<<(double)(n+4)*y/n;
	}
	else {
		fr<<(double)(n+4)*z<<endl;
		fr<<(double)(n+4)*z/n;	
	}	
}
else {
		fr<<n*z<<" "<<a*z<<" "<<b*z<<endl;

	
		fr<<(double)(n+4)*z<<endl;
		fr<<(double)(n+4)*z/n;	
	
	
	
}




fd.close();
fr.close();

return 0;
}

