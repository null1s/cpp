#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Kodas
{
    char raide;
    string kodas;
};

void Skaityti(string &sakinys, Kodas A[], int &n)
{
    ifstream fd("duom.txt");

    getline(fd, sakinys);

    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> A[i].raide >> A[i].kodas;
    }

    fd.close();
}

string RastiKoda(Kodas A[], int n, char c)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i].raide == c)
        {
            return A[i].kodas;
        }
    }

    return "";
}

void Rasyti(string sakinys, Kodas A[], int n)
{
    ofstream fr("rez.txt");

    string zodis = "";

    for (int i = 0; i < sakinys.size(); i++)
    {
        if (sakinys[i] != ' ' && sakinys[i] != '.')
        {
            zodis += sakinys[i];
        }
        else
        {
            for (int j = 0; j < zodis.size(); j++)
            {
                fr << RastiKoda(A, n, zodis[j]);

                if (j != zodis.size() - 1)
                {
                    fr << " ";
                }
            }

            fr << endl;
            zodis = "";
        }
    }

    fr.close();
}

int main()
{
    Kodas A[30];
    int n;
    string sakinys;

    Skaityti(sakinys, A, n);
    Rasyti(sakinys, A, n);

    return 0;
}
