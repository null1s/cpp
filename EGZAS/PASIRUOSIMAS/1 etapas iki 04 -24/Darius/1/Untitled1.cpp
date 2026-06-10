#include<iostream>
#include<conio.h>
using namespace std;
struct skaicius
    {
int sk;
int dalikl=0;
};
int main()
{
int n1, n2;
skaicius A[1000];	
cout<<"Iveskite intervalo pradzia ir pabaiga";
cin>>n1>>n2;
	for(int i=n1; i<=n2; i++){
	A[i].sk=i;
	for(int j=2; j<i; j++){
	if (A[i].sk%j==0) A[i].dalikl++;
	
	}
	cout<<i<<" "<<A[i].dalikl<<endl;
}
return 0;
}

