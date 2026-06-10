#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Automobilis
{
    string pavadinimas;
    int rida;
    int remontas;
};


void Skaityti(Automobilis A[], int &n,
              Automobilis B[], int &m,
              int &maxRida, int &maxRem)
{
    ifstream fd("duom.txt");

    fd >> maxRida >> maxRem;

    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> A[i].pavadinimas
           >> A[i].rida
           >> A[i].remontas;
    }

    fd >> m;

    for (int i = 0; i < m; i++)
    {
        fd >> B[i].pavadinimas
           >> B[i].rida
           >> B[i].remontas;
    }

    fd.close();
}


void Prideti(Automobilis A[], int &n,
             Automobilis B[], int m)
{
    for (int i = 0; i < m; i++)
    {
        A[n] = B[i];
        n++;
    }
}


void Salinti(Automobilis A[], int &n,
             int maxRida, int maxRem)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i].rida > maxRida ||
            A[i].remontas > maxRem)
        {
            for (int j = i; j < n - 1; j++)
            {
                A[j] = A[j + 1];
            }

            n--;
            i--;
        }
    }
}


void Ribiniai(Automobilis A[], int n,
              Automobilis C[], int &k,
              int maxRida)
{
    k = 0;

    int riba = maxRida * 0.85;

    for (int i = 0; i < n; i++)
    {
        if (A[i].rida >= riba)
        {
            C[k] = A[i];
            k++;
        }
    }
}


void Rasyti(Automobilis A[], int n,
            Automobilis C[], int k)
{
    ofstream fr("rez.txt");

    fr << "Naujas automobiliu sarasas:" << endl;

    for (int i = 0; i < n; i++)
    {
        fr << A[i].pavadinimas << " "
           << A[i].rida << " "
           << A[i].remontas << endl;
    }

    fr << endl;

    fr << "Ribines ridos automobiliai:" << endl;

    for (int i = 0; i < k; i++)
    {
        fr << C[i].pavadinimas << " "
           << C[i].rida << " "
           << C[i].remontas << endl;
    }

    fr.close();
}

int main()
{
    Automobilis A[100];
    Automobilis B[100];
    Automobilis C[100];

    int n, m, k;

    int maxRida;
    int maxRem;

    Skaityti(A, n, B, m, maxRida, maxRem);

    Prideti(A, n, B, m);

    Salinti(A, n, maxRida, maxRem);

    Ribiniai(A, n, C, k, maxRida);

    Rasyti(A, n, C, k);

    return 0;
}
