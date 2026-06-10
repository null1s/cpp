#include <iostream>
#include <fstream>

using namespace std;

void skaityti(int &a, int &b, int P[], int &n)
{
    ifstream fd("duom.txt");

    fd >> a >> b;
    fd >> n;

    for(int i = 0; i < n; i++)
    {
        fd >> P[i];
    }

    fd.close();
}

void skaiciuoti(int &a, int &b, int P[], int n,
                int &k1, int &k2,
                int &pirkejai, int &paskutinis)
{
    k1 = 0;
    k2 = 0;
    pirkejai = 0;
    paskutinis = 0;

    for(int i = 0; i < n; i++)
    {
        int kg = P[i];
        int nupirko = 0;

        while(kg >= 2 && b > 0)
        {
            kg -= 2;
            b--;
            k2++;
            nupirko += 2;
        }

        while(kg >= 1 && a > 0)
        {
            kg -= 1;
            a--;
            k1++;
            nupirko += 1;
        }

        if(nupirko > 0)
        {
            pirkejai++;
            paskutinis = nupirko;
        }
    }
}

int main()
{
    int a, b, n;
    int P[100];

    skaityti(a, b, P, n);

    int k1, k2;
    int pirkejai;
    int paskutinis;

    skaiciuoti(a, b, P, n, k1, k2, pirkejai, paskutinis);

    ofstream fr("rez.txt");

    if(k1 == 0)
    {
        fr << "0 ";
    }
    else
    {
        fr << k1 << " ";
    }

    if(k2 == 0)
    {
        fr << "0" << endl;
    }
    else
    {
        fr << k2 << endl;
    }

    fr << paskutinis << endl;

    fr.close();

    return 0;
}
