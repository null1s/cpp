#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Gyventojas
{
    string vardas;
    int butas;
    double sildymas;
    double elektra;
    double vanduo;
};

void Skaityti(int &n, Gyventojas A[])
{
    ifstream fd("duom.txt");

    fd >> n;
    fd.ignore();

    for (int i = 0; i < n; i++)
    {
        string pav, vard;

        fd >> pav >> vard;
        A[i].vardas = pav + " " + vard;

        fd >> A[i].butas
           >> A[i].sildymas
           >> A[i].elektra
           >> A[i].vanduo;
    }

    int m;
    fd >> m;

    for (int i = 0; i < m; i++)
    {
        string pav, vard;
        int but;
        double s, e, v;

        fd >> pav >> vard;
        string pilnas = pav + " " + vard;

        fd >> but >> s >> e >> v;

        for (int j = 0; j < n; j++)
        {
            if (A[j].vardas == pilnas)
            {
                A[j].sildymas += s;
                A[j].elektra += e;
                A[j].vanduo += v;
            }
        }
    }

    fd.close();
}

void Rikiuoti(int n, Gyventojas A[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double suma1 = A[i].sildymas + A[i].elektra + A[i].vanduo;
            double suma2 = A[j].sildymas + A[j].elektra + A[j].vanduo;

            if (suma1 > suma2)
            {
                Gyventojas t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
}

void Spausdinti(int n, Gyventojas A[])
{
    ofstream fr("rez.txt");

    fr << left << setw(20) << "Pavarde vardas"
       << setw(10) << "Butas"
       << setw(12) << "Sildymas"
       << setw(12) << "Elektra"
       << setw(12) << "Vanduo" << endl;

    for (int i = 0; i < n; i++)
    {
        fr << left << setw(20) << A[i].vardas
           << setw(10) << A[i].butas
           << setw(12) << fixed << setprecision(2) << A[i].sildymas
           << setw(12) << A[i].elektra
           << setw(12) << A[i].vanduo << endl;
    }

    fr << endl;
    fr << "Skolininkai:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (A[i].sildymas < 0 ||
            A[i].elektra < 0 ||
            A[i].vanduo < 0)
        {
            fr << left << setw(20) << A[i].vardas
               << setw(10) << A[i].butas
               << setw(12) << fixed << setprecision(2) << A[i].sildymas
               << setw(12) << A[i].elektra
               << setw(12) << A[i].vanduo << endl;
        }
    }

    fr.close();
}

int main()
{
    Gyventojas A[100];
    int n;

    Skaityti(n, A);
    Rikiuoti(n, A);
    Spausdinti(n, A);

    return 0;
}
