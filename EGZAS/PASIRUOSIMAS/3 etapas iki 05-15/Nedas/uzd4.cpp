#include <iostream>
#include <fstream>
using namespace std;

void skaitymas(int R[], int & n)
{
    ifstream fd("duom4.txt");

    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> R[i];
    }

    fd.close();
}

void suradimas(int R[], int n, int & kiekis, int A[])
{
    int D[100], P[100], max_ilgis, pask;

    for (int i = 0; i < n; i++)
    {
        D[i] = 1;
        P[i] = -1;

        for (int j = 0; j < i; j++)
        {
            if (R[j] <= R[i] && D[j] + 1 >= D[i])
            {
                D[i] = D[j] + 1;
                P[i] = j;
            }
        }
    }

    max_ilgis = D[0];
    pask = 0;
    for (int i = 1; i < n; i++)
    {
        if (D[i] > max_ilgis)
        {
            max_ilgis = D[i];
            pask = i;
        }
    }

    kiekis = max_ilgis;

    for (int i = kiekis - 1; i >= 0; i--)
    {
        A[i] = pask + 1;
        pask = P[pask];
    }
}

void isvedimas(int kiekis, int A[])
{
    ofstream fr("rez4.txt");

    fr << kiekis << endl;

    for (int i = 0; i < kiekis; i++)
    {
        fr << A[i] << endl;
    }

    fr.close();
}

int main()
{
    int R[100], n, A[100], kiekis;

    skaitymas(R, n);
    suradimas(R, n, kiekis, A);
    isvedimas(kiekis, A);

    return 0;
}
