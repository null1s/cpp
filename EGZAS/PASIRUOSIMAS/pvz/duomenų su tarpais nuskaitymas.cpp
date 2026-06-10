#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
    string A[100];
    int B[100];
    int n;
    fd >> n;
    fd.ignore();
    for (int i=1;i<=n;i++)
      {
      	 char eil[20];
         fd.get(eil,19);
         A[i]= eil;
         fd >>B[i];
         fd.ignore();
	  }
    for (int i=1;i<=n;i++)
      {
      	 fr<<A[i]<<" "<<B[i]<<endl;
	  }
    fd.close();
    fr.close();
return 0;
}

