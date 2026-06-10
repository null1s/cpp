#include <fstream>
#include <iostream>
using namespace std;

void skaitymas (int & n, int & m, int A[16])
{
    ifstream fd("duom.txt");
    fd >> n;
    for(int i=0; i<n; i++)
    {
        fd>>A[i];
    }
    fd >> m;
    for(int i=0; i<m; i++)
    {
        fd>>A[n+i];
    }
    fd.close();
}

void iterpimas (int & n, int m, int A[16])
{
    int x, j;
    
    for(int i=n; i<n+m; i++)
    {
        x=A[i];
        j=i-1;

        while(j>=0 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    n=n+m;
}

void spausdinimas(int n, int A[16])
{
    ofstream fr("rez.txt");
    for(int i=0; i<n; i++)
    {
        fr<<A[i]<<endl;
    }
    fr.close();
}

int main()
{
    int n, m, A[16];

    skaitymas(n,m,A);
    iterpimas(n,m,A);
    spausdinimas(n,A);

    return 0;
}
