#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void skaityti(string &raktas, string &tekstas)
{
    ifstream fd("duom.txt");

    getline(fd, raktas);
    getline(fd, tekstas);

    fd.close();
}

int rasti(string raktas, char raide)
{
    for (int i = 0; i < raktas.size(); i++)
    {
        if (raktas[i] == raide)
        {
            return i;
        }
    }

    return -1;
}

void sifruoti(string raktas, string tekstas, string &rez)
{
    rez = "";

    for (int i = 0; i < tekstas.size(); i++)
    {
        char c = tekstas[i];

        if (c >= 'a' && c <= 'z')
        {
            int vieta = rasti(raktas, c);

            if (vieta != -1)
            {
                rez = rez + raktas[25 - vieta];
            }
        }
        else
        {
            rez = rez + c;
        }
    }
}

void rasyti(string rez)
{
    ofstream fr("rez.txt");

    fr << rez;

    fr.close();
}

int main()
{
    string raktas;
    string tekstas;
    string rez;

    skaityti(raktas, tekstas);

    sifruoti(raktas, tekstas, rez);

    rasyti(rez);

    return 0;
}
