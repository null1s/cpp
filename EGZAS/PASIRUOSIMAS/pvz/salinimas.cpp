#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
    int A[100], n, x;
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
    fd>> n>> x;
    for (int i=1;i<=n;i++)
    {
    	fd>>A[i];
	}
	
    for(int i=1;i<=n;i++)
    {
    	if(A[i]==x) {
    		        for(int j=i;j<=n;j++)
    		           A[j] = A[j+1];
    		        n--; i--;
	            	}	           	
	}
	
    for (int i=1;i<=n;i++)
    {
    	fr<<A[i]<<" ";
	}
    fd.close();
    fr.close();
return 0;
}

