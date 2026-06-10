#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

struct sokejai{
    string pora;
    int tech[10];
    int art[10];
    int bt;
    int ba;
    int bv;

};
// ------- rikiavimo procedura pagal galutinius balus
void rikiavimas (sokejai A[], int n)
{
     sokejai t;
     for ( int i = 1; i <= n - 1 ; i++)
     for ( int j = i +1; j <= n; j++)
     if (A[i].bv < A[j].bv)
     {
               t = A[i];
               A[i] = A[j];
               A[j] = t;
     }
}
//------ funkcija balu skaiciavimui atmetant min ir max reiksmes
int balai (sokejai A[], int n, int m, int x)
 { int bal;
   int K[10];
   bal=0;
   if (x==0) for (int i=1;i<=m;i++)  // atrenka ka skaiciuoti: uz technika
             K[i] =A[n].tech[i];
   if (x==1) for (int i=1;i<=m;i++) // ar uz artistiskuma
             K[i] =A[n].art[i];
             
    int b;          
    for ( int i = 1; i <=m - 1; i++)
    for ( int j = i+1 ; j <=m ; j++)
    
    if (K[i] > K[j])
    {
             b = K[i];
             K[i] = K[j];
             K[j] = b;
    }
    for (int i=1; i<=m;i++)
	   bal += K[i];
	bal = bal - K[1] - K[m];
	return bal;
}
//----nuskaitymo funkcija
void nuskaitymas(sokejai A[], int &n, int &m){
	ifstream fd("duom.txt");
	fd>>n;
	fd>>m;
	fd.ignore();
	for(int i=1;i<=n;i++)
	    {

	    	char l[20];
		fd.get(l,19);
		A[i].pora=l;

		for(int j=1;j<=m;j++)
			fd>>A[i].tech[j];
			fd.ignore();
		for(int j=1;j<=m;j++)
			fd>>A[i].art[j];
		fd.ignore();
	    
		}

		fd.close();
	}


int main ()
{
 ofstream fr ("rez.txt"); 	
 int n,m;
 sokejai A[50];
 nuskaitymas(A,n,m);
 for(int i=1;i<=n;i++)
   {
    A[i].ba = balai(A,i,m,1);     //skaiciuoja balus uz artistiskuma
	A[i].bt = balai(A,i,m,0);    //skaiciuoja balus uz technika
	A[i].bv = A[i].ba + A[i].bt; // bendra balas	
    }
 rikiavimas (A,n);
 for (int i=1; i<=n;i++)
    fr <<setw(20)<<left<<A[i].pora<<" "<<A[i].bv<<endl;
return 0;
fr.close();
}

