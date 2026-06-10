#include <iostream>
#include <fstream>
using namespace std;

void skaitymas(int pirkejai[], int & n, int & n1, int & n2)
{
    ifstream fd("duom2.txt");

    fd >> n1 >> n2 >> n;
    
    for (int i = 0 ; i < n; i++)
    {
        fd >> pirkejai[i];
    }

    fd.close();
}

void skaiciavimas(int pirkejai[], int n, int & n1, int & n2, int &pard1, int & pard2, int & kiekis, int & paskutinis)
{
    pard1 = 0;
    pard2 = 0;
    kiekis = 0;
    paskutinis = 0;

    for (int i = 0 ; i < n  ; i++)
    {
        int reikia = pirkejai[i];
        int gavo = 0;

        while (reikia >= 2 && n2 > 0)
        {
            n2--;
            pard2++;
            reikia = reikia - 2;
            gavo = gavo + 2;
        }

        while (reikia > 0 && n1 > 0)
        {
            n1--;
            pard1++;
            reikia--;
            gavo++;
        }

        if (gavo > 0)
        {
            kiekis++;
            paskutinis = gavo;
        }
    }
}

void isvedimas(int pard1, int pard2, int kiekis, int paskutinis)
{
    ofstream fr("rez2.txt");

    fr << pard1 << " " << pard2 << endl;
    fr << kiekis << endl;
    fr << paskutinis << endl;

    fr.close();
}

int main()
{
    int pirkejai[100], n1, n2;
    int pard1, pard2, kiekis, paskutinis, n;

    skaitymas(pirkejai, n, n1, n2);
    skaiciavimas(pirkejai, n, n1, n2, pard1, pard2, kiekis, paskutinis);
    isvedimas(pard1, pard2, kiekis, paskutinis);

    return 0;
}
