#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX = 100;

void Skaityti(string fv, double A[], int &n)
{
    ifstream fd(fv.c_str());

    fd >> n;

    for(int i = 0; i < n; i++)
    {
        fd >> A[i];
    }

    fd.close();
}

void Rikiuoti(double A[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(A[i] < A[j])
            {
                double t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
}

void Rasyti(string fr, double A[], int n)
{
    ofstream rez(fr.c_str());

    if(n < 10)
    {
        rez << "Komandai dar truksta "
            << 10 - n
            << " sportininku." << endl;
    }

    rez << "Isrinktu sportininku geriausiu rezultatu sarasas:"
        << endl;

    for(int i = 0; i < n; i++)
    {
        rez << fixed << setprecision(2)
            << A[i] << " ";
    }

    rez.close();
}

int main()
{
    double A[MAX];
    double B[MAX];
    double C[MAX];

    int n, m;
    int k = 0;

    Skaityti("duom1.txt", A, n);
    Skaityti("duom2.txt", B, m);

    for(int i = 0; i < n; i++)
    {
        C[k] = A[i];
        k++;
    }

    for(int i = 0; i < m; i++)
    {
        C[k] = B[i];
        k++;
    }

    Rikiuoti(C, k);

    if(k > 10)
    {
        k = 10;
    }

    Rasyti("rez.txt", C, k);

    return 0;
}
