#include <iostream>
#include <fstream>

using namespace std;

void skaityti(int &n, int &k, int &nr, int A[])
{
    ifstream fd("duom.txt");

    fd >> n >> k >> nr;

    for (int i = 0; i < n; i++)
    {
        fd >> A[i];
    }

    fd.close();
}

void iterpti(int A[], int &n, int vieta, int nr)
{
    for (int i = n; i > vieta; i--)
    {
        A[i] = A[i - 1];
    }

    A[vieta] = nr;
    n++;
}

int paskutinis(int A[], int n, int k)
{
    int indeksas = 0;

    while (n > 1)
    {
        indeksas = (indeksas + k - 1) % n;

        for (int i = indeksas; i < n - 1; i++)
        {
            A[i] = A[i + 1];
        }

        n--;

        if (indeksas == n)
        {
            indeksas = 0;
        }
    }

    return A[0];
}

void rasyti(int A[], int n)
{
    ofstream fr("rez.txt");

    for (int i = 0; i < n; i++)
    {
        fr << A[i] << " ";
    }

    fr.close();
}

int main()
{
    int n, k, nr;
    int A[30];
    int B[30];

    skaityti(n, k, nr, A);

    int vieta = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[j] = A[j];
        }

        int dydis = n;

        iterpti(B, dydis, i, nr);

        if (paskutinis(B, dydis, k) == nr)
        {
            vieta = i;
            break;
        }
    }

    iterpti(A, n, vieta, nr);

    rasyti(A, n);

    return 0;
}
