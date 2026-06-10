#include <iostream>
#include <fstream>

using namespace std;

void Skaityti(int A[], int &n)
{
    ifstream fd("duom.txt");

    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> A[i];
    }

    fd.close();
}

void Rasti(int A[], int n, int B[], int &k)
{
    int maxIlgis = 1;
    int dabIlgis = 1;
    int pradzia = 0;

    int dabPradzia = 0;

    for (int i = 1; i < n; i++)
    {
        if (A[i] >= A[i - 1])
        {
            dabIlgis++;
        }
        else
        {
            dabIlgis = 1;
            dabPradzia = i;
        }

        if (dabIlgis > maxIlgis)
        {
            maxIlgis = dabIlgis;
            pradzia = dabPradzia;
        }
    }

    k = maxIlgis;

    for (int i = 0; i < k; i++)
    {
        B[i] = pradzia + i + 1; 
    }
}

void Rasyti(int B[], int k)
{
    ofstream fr("rez.txt");

    fr << k << endl;

    for (int i = 0; i < k; i++)
    {
        fr << B[i] << endl;
    }

    fr.close();
}

int main()
{
    int A[100];
    int B[100];

    int n;
    int k;

    Skaityti(A, n);

    Rasti(A, n, B, k);

    Rasyti(B, k);

    return 0;
}
