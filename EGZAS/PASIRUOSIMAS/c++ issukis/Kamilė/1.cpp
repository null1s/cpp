#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void rikiuoti(int A[], string D[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(A[i] > A[j])
            {
                swap(A[i], A[j]);
                swap(D[i], D[j]);
            }
        }
    }
}

double vidurkis(int A[], int n)
{
    int suma = 0;

    for(int i = 0; i < n; i++)
    {
        suma += A[i];
    }

    return (double)suma / n;
}

bool pirminis(int x)
{
    if(x < 2)
    {
        return false;
    }

    for(int i = 2; i < x; i++)
    {
        if(x % i == 0)
        {
            return false;
        }
    }

    return true;
}

int pirmasSk(string s)
{
    string sk = "";

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            sk += s[i];
        }
        else
        {
            break;
        }
    }

    int x = 0;

    for(int i = 0; i < sk.length(); i++)
    {
        x = x * 10 + (sk[i] - '0');
    }

    return x;
}

int main()
{
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");

    string D[100];
    int A[100];

    int n;
    fd >> n;

    for(int i = 0; i < n; i++)
    {
        fd >> D[i] >> A[i];
    }

    rikiuoti(A, D, n);

    fr << "Temperaturos didejimo tvarka" << endl;

    for(int i = 0; i < n; i++)
    {
        fr << D[i] << " " << A[i] << endl;
    }

    fr << endl;

    string unD[100];
    int kiek = 0;

    for(int i = 0; i < n; i++)
    {
        bool yra = false;

        for(int j = 0; j < kiek; j++)
        {
            if(D[i] == unD[j])
            {
                yra = true;
            }
        }

        if(!yra)
        {
            unD[kiek] = D[i];
            kiek++;
        }
    }

    fr << "Vidutines temperaturos" << endl;

    for(int i = 0; i < kiek; i++)
    {
        int B[100];
        int k = 0;

        for(int j = 0; j < n; j++)
        {
            if(unD[i] == D[j])
            {
                B[k] = A[j];
                k++;
            }
        }

        fr << unD[i] << " " << vidurkis(B, k) << endl;
    }

    fr << endl;
    fr << "Nepirminiai skaiciai" << endl;

    for(int i = 0; i < n; i++)
    {
        if(!pirminis(A[i]))
        {
            fr << D[i] << " " << A[i] << endl;
        }
    }

    fr << endl;
    fr << "Dregmes duomenys" << endl;

    string diena;
    string skaiciai;

    while(fd >> diena >> skaiciai)
    {
        int x = pirmasSk(skaiciai);

        fr << diena << " " << x << endl;
    }

    fd.close();
    fr.close();

    return 0;
}
