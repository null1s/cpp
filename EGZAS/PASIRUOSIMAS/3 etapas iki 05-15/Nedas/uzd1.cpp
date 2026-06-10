#include <iostream>
#include <fstream>
using namespace std;

void skaitymas(int vaikai[], int & n, int & k, int & naujas)
{
    ifstream fd("duom1.txt");

    fd >> n >> k >> naujas;

    for (int i = 0; i < n ; i++)
    {
        fd >> vaikai[i];
    }

    fd.close();
}

void iterpimas(int vaikai[], int & n, int vieta, int naujas)
{
    for (int i = n ; i > vieta ; i--)
    {
        vaikai[i] = vaikai[i - 1];
    }

    vaikai[vieta] = naujas;
    n++;
}

void salinimas(int vaikai[], int &n, int vieta)
{
    for (int i = vieta ; i < n - 1; i++)
    {
        vaikai[i] = vaikai[i + 1];
    }

    n--;
}

int tikrinimas(int vaikai[], int n, int k)
{
    int vieta = 0;

    while (n > 1)
    {
        vieta = (vieta + k - 1) % n;

        salinimas(vaikai, n, vieta);

        if (vieta == n)
        {
            vieta = 0;
        }
    }

    return vaikai[0];
}

void kopijavimas(int a[], int tikr[], int n)
{
    for (int i = 0 ; i<n ; i++)
    {
        tikr[i] = a[i];
    }
}

int radimas(int vaikai[], int n, int k, int naujas)
{
    int tikr[100], kiekis;

    for (int i = 0 ; i <= n ; i++)
    {
        kopijavimas(vaikai, tikr, n);

        kiekis = n;

        iterpimas(tikr, kiekis, i, naujas);

        if (tikrinimas(tikr, kiekis, k) == naujas)
        {
            return i;
        }
    }

    return 0;
}

void isvedimas(int vaikai[], int n)
{
    ofstream fr("rez1.txt");

    for (int i = 0 ; i < n ; i++)
    {
        fr << vaikai[i] << " ";
    }

    fr.close();
}

int main()
{
    int vaikai[100], n, k, naujas, vieta;

    skaitymas(vaikai, n, k, naujas);
    vieta = radimas(vaikai, n, k, naujas);
    iterpimas(vaikai, n, vieta, naujas);
    isvedimas(vaikai, n);

    return 0;
}
