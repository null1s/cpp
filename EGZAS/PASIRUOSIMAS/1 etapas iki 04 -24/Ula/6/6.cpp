#include<fstream>
#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;

int main ()
{
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");

    string nr;
    long long sk;
    fd>>nr>>sk;
    
    int n=0, suma=0;
    long long k=sk, A[16];
    
    while (k>0)
    {
    	k=k/10;
    	n++;
	}
    
    k=sk;
    
    for (int i=n-1; i>=0; i--)
    {
    	A[i]=k%10;
    	k=k/10;
    }
  
    for (int i=0; i<n; i++)
    {
    	if (i%2!=0)
		{
		    A[i]=A[i]*2;
		    if (A[i]>=10)
		    {
		    	A[i]=A[i]/10+A[i]%10;
			}
		}
		suma+=A[i];		
	}
	
	if (suma%10==0) cout<<"Teisingas";
	else cout<<"Neteisingas";

    fd.close();
    fr.close();
    return 0;
}




