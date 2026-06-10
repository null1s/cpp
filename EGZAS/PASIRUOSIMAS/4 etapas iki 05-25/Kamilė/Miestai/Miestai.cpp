#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Miestas
{
    string miestas;
    string valstybe;
};

struct Valstybe
{
    string pavadinimas;
    int kiekis;
};

void Skaityti(Miestas A[], int &n)
{
    ifstream fd("duom.txt");

    fd >> n;
    fd.ignore();

    for (int i = 0; i < n; i++)
    {
        fd >> A[i].miestas;
        getline(fd, A[i].valstybe);

        while (A[i].valstybe[0] == ' ')
        {
            A[i].valstybe.erase(0, 1);
        }
    }

    fd.close();
}

bool Yra(Valstybe B[], int m, string vardas)
{
    for (int i = 0; i < m; i++)
    {
        if (B[i].pavadinimas == vardas)
        {
            return true;
        }
    }

    return false;
}

int Rasti(Valstybe B[], int m, string vardas)
{
    for (int i = 0; i < m; i++)
    {
        if (B[i].pavadinimas == vardas)
        {
            return i;
        }
    }

    return -1;
}

void Atrinkti(Miestas A[], int n, Valstybe B[], int &m)
{
    m = 0;

    for (int i = 0; i < n; i++)
    {
        if (Yra(B, m, A[i].valstybe) == false)
        {
            B[m].pavadinimas = A[i].valstybe;
            B[m].kiekis = 1;
            m++;
        }
        else
        {
            int x = Rasti(B, m, A[i].valstybe);
            B[x].kiekis++;
        }
    }
}

void Spausdinti(Valstybe B[], int m)
{
    ofstream fr("rez.txt");

    fr << "Valstybiu sarasas:" << endl;

    for (int i = 0; i < m; i++)
    {
        fr << B[i].pavadinimas << " " << B[i].kiekis << endl;
    }

    fr.close();
}

int main()
{
    Miestas A[300];
    Valstybe B[300];

    int n, m;

    Skaityti(A, n);
    Atrinkti(A, n, B, m);
    Spausdinti(B, m);

    return 0;
}
