#include <iostream>
#include <fstream>
using namespace std;

void skaitymas1(int anglai[], int & buriai)
{
    ifstream fd("anglija.txt");

    int sk, didz;

    fd >> buriai;

    for (int i = 0; i < buriai; i++)
    {
        fd >> didz;

        for (int j = 1; j < 4; j++)
        {
            fd >> sk;

            if (sk > didz)
            {
                didz = sk;
            }
        }

        anglai[i] = didz;
    }

    fd.close();
}

void skaitymas2(int prancuzai[], int & buriai)
{
    ifstream fd("prancuzija.txt");

    int sk, didz;

    fd >> buriai;

    for (int i = 0; i < buriai; i++)
    {
        fd >> didz;

        for (int j = 1; j < 4; j++)
        {
            fd >> sk;

            if (sk > didz)
            {
                didz = sk;
            }
        }

        prancuzai[i] = didz;
    }

    fd.close();
}

void skaiciavimas(int anglai[], int prancuzai[], int buriai, int & anglu_taskai, int & prancuzu_taskai)
{
    anglu_taskai = 0;
    prancuzu_taskai = 0;

    for (int i = 0; i < buriai; i++)
    {
        if (anglai[i] > prancuzai[i])
        {
            anglu_taskai++;
        }
        else if (prancuzai[i] > anglai[i])
        {
            prancuzu_taskai++;
        }
    }
}

void isvedimas(int anglu_taskai, int prancuzu_taskai)
{
    ofstream fr("laimetojas.txt");

    fr << "Anglija surinko: " << anglu_taskai << endl;
    fr << "Prancuzija surinko: " << prancuzu_taskai << endl;

    if (anglu_taskai > prancuzu_taskai)
    {
        fr << "Laimejo: Anglija";
    }
    else if (prancuzu_taskai > anglu_taskai)
    {
        fr << "Laimejo: Prancuzija";
    }
    else
    {
        fr << "Lygiosios";
    }

    fr.close();
}

int main()
{
    int anglai[100], prancuzai[100], buriai, anglu_taskai, prancuzu_taskai;

    skaitymas1(anglai, buriai);
    skaitymas2(prancuzai, buriai);
    skaiciavimas(anglai, prancuzai, buriai, anglu_taskai, prancuzu_taskai);
    isvedimas(anglu_taskai, prancuzu_taskai);

    return 0;
}
