#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;

void Skaityti(string fv, int A[], int &n, int B[], int &m)
{
    ifstream fd(fv.c_str());

    fd >> n;

    for(int i = 0; i < n; i++)
    {
        fd >> A[i];
    }

    fd >> m;

    for(int i = 0; i < m; i++)
    {
        fd >> B[i];
    }

    fd.close();
}

void Iterpti(int A[], int &n, int x)
{
    int i = n - 1;

    while(i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }

    A[i + 1] = x;
    n++;
}

void Rasyti(string fr, int A[], int n)
{
    ofstream rez(fr.c_str());

    for(int i = 0; i < n; i++)
    {
        rez << A[i] << endl;
    }

    rez.close();
}

int main()
{
    int A[MAX];
    int B[MAX];

    int n, m;

    Skaityti("duom.txt", A, n, B, m);

    for(int i = 0; i < m; i++)
    {
        Iterpti(A, n, B[i]);
    }

    Rasyti("rez.txt", A, n);

    return 0;
}
