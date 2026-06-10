#include <iostream>
#include <fstream>
using namespace std;

void skaitymas1(double rez[], int & n)
{
    ifstream fd("duom7_1.txt");

    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> rez[i];
    }

    fd.close();
}

void skaitymas2(double rez[], int & n)
{
    ifstream fd("duom7_2.txt");

    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> rez[i];
    }

    fd.close();
}

int vietos_radimas(double rez[], int etapas[], int n, double sk, int e)
{
    for (int i = 0; i < n; i++)
    {
        if (sk < rez[i])
        {
            return i;
        }

        if (sk == rez[i] && e < etapas[i])
        {
            return i;
        }
    }

    return n;
}

void iterpimas(double rez[], int etapas[], int & n, double sk, int e)
{
    int vieta;

    vieta = vietos_radimas(rez, etapas, n, sk, e);

    for (int i = n; i > vieta; i--)
    {
        rez[i] = rez[i - 1];
        etapas[i] = etapas[i - 1];
    }

    rez[vieta] = sk;
    etapas[vieta] = e;
    n++;
}

void salinimas(double rez[], int etapas[], int & n, int vieta)
{
    for (int i = vieta; i < n - 1; i++)
    {
        rez[i] = rez[i + 1];
        etapas[i] = etapas[i + 1];
    }

    n--;
}

void atranka(double pirmas[], int n, double antras[], int m, double ats[], int etapas[], int & kiekis)
{
    kiekis = 0;

    for (int i = 0; i < m; i++)
    {
        iterpimas(ats, etapas, kiekis, antras[i], 2);
    }

    for (int i = 0; i < n; i++)
    {
        iterpimas(ats, etapas, kiekis, pirmas[i], 1);
    }

    while (kiekis > 10)
    {
        salinimas(ats, etapas, kiekis, 0);
    }
}

void isvedimas(double ats[], int kiekis)
{
    ofstream fr("rez7.txt");

    if (kiekis < 10)
    {
        fr << "Komandai dar truksta " << 10 - kiekis << " sportininkiu." << endl;
    }

    fr << "Isrinktu sportininkiu geriausiu rezultatu sarasas:" << endl;

    for (int i = 0; i < kiekis; i++)
    {
        fr << ats[i] << " ";
    }

    fr.close();
}

int main()
{
    double pirmas[100], antras[100], ats[100];
    int etapas[100];
    int n, m, kiekis;

    skaitymas1(pirmas, n);
    skaitymas2(antras, m);

    atranka(pirmas, n, antras, m, ats, etapas, kiekis);
    isvedimas(ats, kiekis);

    return 0;
}
