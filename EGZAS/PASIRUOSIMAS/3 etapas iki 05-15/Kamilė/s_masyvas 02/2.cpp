#include <iostream>
#include <fstream>

using namespace std;

void skaityti(int &n1, int &n2, int &n, int A[])
{
    ifstream fd("duom.txt");

    fd >> n1 >> n2;
    fd >> n;

    for (int i = 0; i < n; i++)
    {
        fd >> A[i];
    }

    fd.close();
}

void skaiciuoti(int A[], int n, int &n1, int &n2,
                int &parduota1, int &parduota2,
                int &pirkeju, int &paskutinis)
{
    parduota1 = 0;
    parduota2 = 0;
    pirkeju = 0;
    paskutinis = 0;

    for (int i = 0; i < n; i++)
    {
        int reikia = A[i];
        int gavo = 0;

        while (reikia >= 2 && n2 > 0)
        {
            reikia = reikia - 2;
            n2--;
            parduota2++;
            gavo = gavo + 2;
        }

        while (reikia >= 1 && n1 > 0)
        {
            reikia = reikia - 1;
            n1--;
            parduota1++;
            gavo = gavo + 1;
        }

        if (gavo > 0)
        {
            pirkeju++;
            paskutinis = gavo;
        }

        if (n1 == 0 && n2 == 0)
        {
            break;
        }
    }
}

void rasyti(int parduota1, int parduota2,
            int pirkeju, int paskutinis)
{
    ofstream fr("rez.txt");

    fr << parduota1 << " " << parduota2 << endl;
    fr << pirkeju << endl;
    fr << paskutinis << endl;

    fr.close();
}

int main()
{
    int n1, n2, n;
    int A[100];

    int parduota1, parduota2;
    int pirkeju, paskutinis;

    skaityti(n1, n2, n, A);

    skaiciuoti(A, n, n1, n2,
               parduota1, parduota2,
               pirkeju, paskutinis);

    rasyti(parduota1, parduota2,
           pirkeju, paskutinis);

    return 0;
}
