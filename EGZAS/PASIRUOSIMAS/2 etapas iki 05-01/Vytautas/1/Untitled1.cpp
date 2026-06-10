#include<iostream>
#include<fstream>
#include<math.h>
#include<iomanip>
using namespace std;
void line (int x1, int y1, int x2, int y2, int A[]) {

for(int i=1;i<=3;i++){
	A[i]=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	
}
}
void plotas ( int A[], double & S  ){
double p=(A[1]+A[2]+A[3] )/2;

S=sqrt(p*(p-A[1])*(p-A[2])*(p-A[3]));
	
}

int main() {
int A[3];
int ax,ay,bx,by,cx,cy;
ifstream fd("duom.txt");
ofstream fr("rez.txt");
fd>>ax>>ay>>bx>>by>>cx>>cy;
for( int j=1;j<=3;j++){
	if( j==1 ) line(ax,ay,bx,by,A);
	if( j==2) line(bx,by,cx,cy,A);
	else line(cx,cy,ax,ay,A);
	
	
}
double S;
plotas(A,S);
fr<<fixed<<setprecision(2)<<S;

fd.close();
fr.close();

return 0;
}

