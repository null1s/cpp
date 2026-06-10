#include <iostream>
#include <fstream>
using namespace std;

void skaiciuoti(int A[], int &suma, int &dienos, int &virsijo, int &nepasieke)
{
    int norma[3] = {5, 6, 4};

    suma = 0;
    dienos = 0;
    virsijo = 0;
    nepasieke = 0;

    for (int i = 0; i < 3; i++)
    {
        suma += A[i];

        if (A[i] > 0)
            dienos++;

        if (A[i] > norma[i])
            virsijo++;
        else if (A[i] < norma[i])
            nepasieke++;
    }
}
int main()
{
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");

    int n;
    fd >> n;

    int A[3]; 

    int visoVal = 0;
    int visoDienu = 0;
    int visoVirsijo = 0;
    int visoNepasieke = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            fd >> A[j];

        int suma, dienos, virsijo, nepasieke;

        skaiciuoti(A, suma, dienos, virsijo, nepasieke);

        fr << suma << " " << dienos << " "
           << virsijo << " " << nepasieke << endl;

        visoVal += suma;
        visoDienu += dienos;
        visoVirsijo += virsijo;
        visoNepasieke += nepasieke;
    }

    fr << visoVal << " " << visoDienu << " "
       << visoVirsijo << " " << visoNepasieke;

    fd.close();
    fr.close();

    return 0;
}
