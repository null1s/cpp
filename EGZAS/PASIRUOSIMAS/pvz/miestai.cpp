#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
struct salis {
	  string mst;
	  string sls;
	  int kiek=1;
};
void skaitymas(salis A[],int & n)
{
		ifstream fd ("duom.txt");
		fd>>n;
		fd.ignore();
		for (int i=1;i<=n;i++) // fd.ignore(20)
      {
      	 char eil[20];
         fd.get(eil,20);
         A[i].mst= eil;
         fd>>A[i].sls;
         fd.ignore();
	  }
}
//--------skaitymo funkcija
void rasyti (salis A[],int n)
{   ofstream fr ("rez.txt");
	for (int i=1;i<=n;i++)
	{
		fr<<A[i].sls<<" "<<A[i].kiek<<endl;
	}
	fr.close();
}
bool yra (string s,string m)
{   bool ats;
    if (s==m ) ats = true;
          else ats =false;
	return ats;
}
void atrinkti (salis A[], int & n)
{
	for (int i=1;i<=n;i++)
	{
	for (int k = i+1; k<=n; k++)
	{
	if (yra (A[i].sls,A[k].sls))
	    {
	    for (int j = k; j<n; j++)
	   	    A[j]=A[j+1];
	   	    A[i].kiek++;
	   	n--;i--;
       }
   }
}
}
int main()
{   
    salis A[300];int n;
   
    skaitymas (A,n);
     atrinkti(A,n);
    rasyti(A,n);
    
return 0;
}

