#include <iostream>
#include <fstream>
using namespace std;

void skaitymas(string pav[], int rida[], int remontas[], int & n, int & m, int & max_rida, int & max_dienos)
{
    ifstream fd("duom5.txt");

    fd >> max_rida >> max_dienos >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> pav[i] >> rida[i] >> remontas[i];
    }

    fd >> m;

    for (int i = 0; i < m; i++)
    {
        fd >> pav[n + i] >> rida[n + i] >> remontas[n + i];
    }
    
	n = n + m;
    fd.close();
}

void salinimas(string pav[], int rida[], int remontas[], int & n, int max_rida, int max_dienos)
{
    for (int i = 0; i < n; i++)
    {
        if (rida[i] > max_rida || remontas[i] > max_dienos)
        {
            for (int j = i; j < n - 1; j++)
            {
                pav[j] = pav[j + 1];
                rida[j] = rida[j + 1];
                remontas[j] = remontas[j + 1];
            }

            n--;
            i--;
        }
    }
}

void ribiniai(string pav[], int rida[], int remontas[], int n, int max_rida, string pav2[], int rida2[], int remontas2[], int & kiekis)
{
    kiekis = 0;

    for (int i = 0; i < n; i++)
    {
        if (rida[i] >= max_rida * 85 / 100)
        {
            pav2[kiekis] = pav[i];
            rida2[kiekis] = rida[i];
            remontas2[kiekis] = remontas[i];
            kiekis++;
        }
    }
}

void isvedimas(string pav[], int rida[], int remontas[], int n, string pav2[], int rida2[], int remontas2[], int kiekis)
{
    ofstream fr("rez5.txt");

    fr << "Naujas sarasas:" << endl;

    for (int i = 0; i < n; i++)
    {
        fr << pav[i] << " " << rida[i] << " " << remontas[i] << endl;
    }

    fr << endl;
    fr << "Ribines ridos automobiliai: " << endl;

    for (int i = 0; i < kiekis; i++)
    {
        fr << pav2[i] << " " << rida2[i] << " " << remontas2[i] << endl;
    }

    fr.close();
}

int main()
{
    string pav[100], pav2[100];
    int rida[100], remontas[100];
    int rida2[100], remontas2[100];
    int n, m, max_rida, max_dienos, kiekis;

    skaitymas(pav, rida, remontas, n, m, max_rida, max_dienos);
    salinimas(pav, rida, remontas, n, max_rida, max_dienos);
    ribiniai(pav, rida, remontas, n, max_rida, pav2, rida2, remontas2, kiekis);
    isvedimas(pav, rida, remontas, n, pav2, rida2, remontas2, kiekis);

    return 0;
}
