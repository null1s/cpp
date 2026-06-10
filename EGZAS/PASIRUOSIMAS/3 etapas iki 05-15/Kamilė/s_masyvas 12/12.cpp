#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void skaityti(int A[], int B[], int C[], int &n)
{
    ifstream fd("duom.txt");

    fd >> n;

    for(int i = 0; i < n; i++)
    {
        fd >> A[i] >> B[i] >> C[i];
    }

    fd.close();
}

double taskai(int l, int d, int p)
{
    return l * 1 + d * 0.5;
}

void rikiuoti(double T[], int N[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(T[i] < T[j])
            {
                swap(T[i], T[j]);
                swap(N[i], N[j]);
            }

            if(T[i] == T[j] && N[i] > N[j])
            {
                swap(T[i], T[j]);
                swap(N[i], N[j]);
            }
        }
    }
}

double maziausias(double T[], int n)
{
    double m = T[0];

    for(int i = 1; i < n; i++)
    {
        if(T[i] < m)
        {
            m = T[i];
        }
    }

    return m;
}

double didziausias(double T[], int n)
{
    double d = T[0];

    for(int i = 1; i < n; i++)
    {
        if(T[i] > d)
        {
            d = T[i];
        }
    }

    return d;
}

int main()
{
    int A[10], B[10], C[10];
    int n;

    skaityti(A, B, C, n);

    double T[10];
    int N[10];

    for(int i = 0; i < n; i++)
    {
        T[i] = taskai(A[i], B[i], C[i]);
        N[i] = i + 1;
    }

    double min = maziausias(T, n);
    double max = didziausias(T, n);

    rikiuoti(T, N, n);

    ofstream fr("rez.txt");

    fr << "Sportininku rezultatai:" << endl;

    for(int i = 0; i < n; i++)
    {
        fr << N[i] << " " << fixed << setprecision(1) << T[i] << endl;
    }

    fr << "Maziausiai tasku surinke sportininkai:" << endl;

    for(int i = 0; i < n; i++)
    {
        double t = taskai(A[i], B[i], C[i]);

        if(t == min)
        {
            fr << i + 1 << " ";
        }
    }

    fr << endl;

    fr << "Daugiausiai tasku surinke sportininkai:" << endl;

    for(int i = 0; i < n; i++)
    {
        double t = taskai(A[i], B[i], C[i]);

        if(t == max)
        {
            fr << i + 1 << " ";
        }
    }

    fr << endl;

    fr.close();

    return 0;
}
