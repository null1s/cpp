#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void skaiciuoti(int n, double A[],
                double ang100, double bal100, double rie100,
                double B[], double C[], double D[])
{
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i] * ang100 / 100.0;
        C[i] = A[i] * bal100 / 100.0;
        D[i] = A[i] * rie100 / 100.0;
    }
}

int kiekDienu(int n, double A[], double kcal100)
{
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        double kcal = A[i] * kcal100 / 100.0;
        if (kcal >= 1800)
            k++;
    }

    return k;
}
int main()
{
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int n;
    fd >> n;
    double ang100, bal100, rie100;
    fd >> ang100 >> bal100 >> rie100;
    double A[100];
    for (int i = 0; i < n; i++)
        fd >> A[i];
    double kcal100 = 349;
    double B[100], C[100], D[100];
    skaiciuoti(n, A, ang100, bal100, rie100, B, C, D);
    for (int i = 0; i < n; i++)
    {
        fr << fixed << setprecision(1)
           << B[i] << " "
           << C[i] << " "
           << D[i] << endl;
    }
    int k = kiekDienu(n, A, kcal100);
    fr << "Vaida suvartojo reikiama kaloriju kieki "
       << k << " dienas";
    fd.close();
    fr.close();

    return 0;
}
