#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void Skaityti(double A[], int &n)
{
    ifstream fd("duom.txt");

    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> A[i];
    }

    fd.close();
}

double Vidurkis(double A[], int n)
{
    double suma = 0;

    for (int i = 0; i < n; i++)
    {
        suma += A[i];
    }

    return suma / n;
}

int Rasti(double A[], int n, double vid)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] <= vid)
        {
            return i;
        }
    }

    return -1;
}

void Salinti(double A[], int &n, int poz)
{
    for (int i = poz; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }

    n--;
}


void Rikiuoti(double A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                double laik = A[i];
                A[i] = A[j];
                A[j] = laik;
            }
        }
    }
}


void Rasyti(double A[], int n)
{
    ofstream fr("rez.txt");

    fr << "Finale dalyvaus " << n << " mokiniai" << endl;
    fr << "Ju pasiekti rezultatai:" << endl;

    for (int i = 0; i < n; i++)
    {
        fr << fixed << setprecision(2)
           << A[i] << " ";
    }

    fr.close();
}

int main()
{
    double A[100];

    int n;

    Skaityti(A, n);

    double vid = Vidurkis(A, n);

    int poz = Rasti(A, n, vid);

    while (poz != -1)
    {
        Salinti(A, n, poz);

        poz = Rasti(A, n, vid);
    }

    Rikiuoti(A, n);

    Rasyti(A, n);

    return 0;
}
