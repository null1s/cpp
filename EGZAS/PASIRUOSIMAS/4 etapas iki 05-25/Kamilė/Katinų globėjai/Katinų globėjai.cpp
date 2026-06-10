#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Vaikas
{
    string vardas;
    int lt, ct;
    int d, k;
    int kpLt, kpCt;
    int taup;
};

int ICentus(int lt, int ct)
{
    return lt * 100 + ct;
}

void IsCentu(int suma, int &lt, int &ct)
{
    lt = suma / 100;
    ct = suma % 100;
}

void Skaityti(Vaikas A[], int &n)
{
    ifstream fd("duom.txt");

    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> A[i].vardas;
        fd >> A[i].lt >> A[i].ct;
        fd >> A[i].d >> A[i].k;
        fd >> A[i].kpLt >> A[i].kpCt;

        int turi = ICentus(A[i].lt, A[i].ct);
        int kaina = ICentus(A[i].kpLt, A[i].kpCt);

        A[i].taup = turi - A[i].d * A[i].k * kaina;
    }

    fd.close();
}

void Daugiausia(Vaikas A[], int n, string &vardas, int &suma)
{
    suma = A[0].taup;
    vardas = A[0].vardas;

    for (int i = 1; i < n; i++)
    {
        if (A[i].taup > suma)
        {
            suma = A[i].taup;
            vardas = A[i].vardas;
        }
    }
}

void Likutis(Vaikas A[], int n, int &liko)
{
    liko = 0;

    for (int i = 0; i < n; i++)
    {
        liko += A[i].taup;
    }
}

void Rasyti(Vaikas A[], int n)
{
    ofstream fr("rez.txt");

    for (int i = 0; i < n; i++)
    {
        int lt, ct;
        IsCentu(A[i].taup, lt, ct);

        fr << A[i].vardas << " ";
        fr << lt << " ";

        if (ct < 10) fr << 0;

        fr << ct << endl;
    }

    int liko;
    Likutis(A, n, liko);

    int lt, ct;
    IsCentu(liko, lt, ct);

    fr << lt << " ";

    if (ct < 10) fr << 0;

    fr << ct << endl;

    string vardas;
    int suma;

    Daugiausia(A, n, vardas, suma);

    IsCentu(suma, lt, ct);

    fr << vardas << " ";
    fr << lt << " ";

    if (ct < 10) fr << 0;

    fr << ct << endl;

    fr.close();
}

int main()
{
    Vaikas A[10];
    int n;

    Skaityti(A, n);
    Rasyti(A, n);

    return 0;
}
