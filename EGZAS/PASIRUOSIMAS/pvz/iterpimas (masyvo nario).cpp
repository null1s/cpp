#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
    int A[10], n, x, vieta,kiek;
    fd>> n>>x;
    for (int i=0;i<n;i++)
    {
    	fd>>A[i];
	cout <<A[i]<<" ";
	}
	for (int i=0;i<n;i++)
	{
	if(A[i]>0){ 	kiek=A[i];	
	for(int z=0;z<kiek;z++)
	{	
	for (int j=n;j>i;j--)
	    {
	    	A[j] = A[j-1];
		}

	A[i+1]=x;
    n++;i++;
    }
	}
    }
     for (int i=0;i<n;i++)
     {
     	cout <<A[i]<<" ";
	 }
    fd.close();
    fr.close();
return 0;
}

