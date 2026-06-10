#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
   
   int x, y, sk=0;
   cout<<"Iveskite intervalo pradzia ir pabaiga: "<<endl;
   cin>>x>>y;
   
   cout<<"Skaicius | Dalijasi is: "<<endl;
   for(int i=x; i<=y; i++)
   {
   	  sk=0;
   	  
   	  for (int j=2; j<i; j++)
   	  {
   	  	if (i%j==0) sk++;
	  }
	
	  cout<<i<<"            "<<sk<<endl;
   }
   
return 0;
}

