#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void skaitymas(int &n, double M[])
{
    ifstream fd("duom6.txt");

    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> M[i];
    }

    fd.close();
}

double vidurkio_skaiciavimas(int n, double M[])
{
    double suma = 0;

    for (int i = 0; i < n; i++)
    {
        suma = suma + M[i];
    }

    return suma / n;
}

void suradimas(int n, double M[], double vidurkis, int & indeksas)
{
    indeksas = -1;

    for (int i = 0; i < n; i++)
    {
        if (M[i] <= vidurkis)
        {
            indeksas = i;
            return;
        }
    }
}

void salinimas(int &n, double M[], int indeksas)
{
    for (int i = indeksas; i < n - 1; i++)
    {
        M[i] = M[i + 1];
    }

    n--;
}

void rikiavimas(int n, double M[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (M[j] > M[j + 1])
            {
                double laikinas = M[j];
                M[j] = M[j + 1];
                M[j + 1] = laikinas;
            }
        }
    }
}

void isvedimas(int n, double M[])
{
    ofstream fr("rez6.txt");

    fr << "Finale dalyvaus " << n << " mokiniai" << endl;
    fr << "Ju pasiekti rezultatai:" << endl;

    for (int i = 0; i < n; i++)
    {
        fr << fixed << setprecision(2) << M[i] << " ";
    }

    fr.close();
}

int main()
{
    int n, indeksas;
    double M[100];

    skaitymas(n, M);

    double vidurkis = vidurkio_skaiciavimas(n, M);

    while (true)
    {
        suradimas(n, M, vidurkis, indeksas);

        if (indeksas == -1)
        {
            break;
        }

        salinimas(n, M, indeksas);
    }

    rikiavimas(n, M);

    isvedimas(n, M);

    return 0;
}
