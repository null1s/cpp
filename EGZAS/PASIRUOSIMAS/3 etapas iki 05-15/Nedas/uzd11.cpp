#include <iostream>
#include <fstream>
using namespace std;

void skaitymas(int pirma[], int antra[], int trecia[], int ketvirta[], int & n)
{
    ifstream fd("duom11.txt");

    fd >> n;

    for (int i = 0 ; i < n ; i++)
    {
        fd >> pirma[i] >> antra[i] >> trecia[i] >> ketvirta[i];
    }

    fd.close();
}

int deliones(int pirma[], int antra[], int trecia[], int ketvirta[], int n)
{
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int s4 = 0;

    for (int i = 0 ; i < n; i++)
    {
        s1 = s1 + pirma[i];
        s2 = s2 + antra[i];
        s3 = s3 + trecia[i];
        s4 = s4 + ketvirta[i];
    }

    int kiekis = s1 / 2;

    if (s2 / 2 < kiekis)
    {
        kiekis = s2 / 2;
    }

    if (s3 / 4 < kiekis)
    {
        kiekis = s3 / 4;
    }

    if (s4 / 4 < kiekis)
    {
        kiekis = s4 / 4;
    }

    return kiekis;
}

void likutis(int pirma[], int antra[], int trecia[], int ketvirta[], int n, int kiekis, int liko[])
{
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int s4 = 0;

    for (int i = 0 ; i < n ; i++)
    {
        s1 = s1 + pirma[i];
        s2 = s2 + antra[i];
        s3 = s3 + trecia[i];
        s4 = s4 + ketvirta[i];
    }

    liko[0] = s1 - kiekis * 2;
    liko[1] = s2 - kiekis * 2;
    liko[2] = s3 - kiekis * 4;
    liko[3] = s4 - kiekis * 4;
}

void isvedimas(int kiekis , int liko[])
{
    ofstream fr("rez11.txt");

    fr << "Sudaromi " << kiekis << " delioniu komplektai." << endl;
    fr << "Lieka nepanaudoti " << liko[0] <<" pirmos rusies paveiksleliai." << endl;
    fr << "Lieka nepanaudoti " << liko[1] << " antros rusies paveiksleliai." << endl;
    fr << "Trecios rusies paveiksleliu nelieka." << endl;
    fr << "Lieka nepanaudoti " << liko[3]  << " ketvirtos rusies paveiksleliai." << endl;

    fr.close();
}

int main()
{
    int pirma[100], antra[100], trecia[100], ketvirta[100];
    int liko[4], n, kiekis;

    skaitymas(pirma, antra, trecia, ketvirta, n);
    kiekis = deliones(pirma, antra, trecia, ketvirta, n);
    likutis(pirma, antra, trecia, ketvirta, n, kiekis, liko);
    isvedimas(kiekis, liko);

    return 0;
}
