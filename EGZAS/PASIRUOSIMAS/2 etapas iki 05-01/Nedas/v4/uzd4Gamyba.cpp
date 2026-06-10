#include <fstream>
using namespace std;

void skaiciavimas(int a, int b, int h1, int h2, int h3, int h4, 
int P[], int A[], int & didz_pirmas, int & didz_antras, int & didzPelnas)
{
    for (int i = 0; i < 100; i++) 
    {
        for (int j = 0; j < 100; j++) 
        {
            if (P[0]*i + A[0]*j <= h1 && P[1]*i + A[1]*j <= h2 &&
                P[2]*i + A[2]*j <= h3 && P[3]*i + A[3]*j <= h4) 
            {
                int pelnas = a * i + b * j;

                if (pelnas > didzPelnas) 
                {
                    didzPelnas = pelnas;
                    didz_pirmas = i;
                    didz_antras = j;
                }
            }
        }
    }
}

int main() 
{
    ifstream fd("duom4Gamyba.txt");
    ofstream fr("rez4Gamyba.txt");
    
    int a, b, P[10], A[10], h1, h2, h3, h4;
  
    fd >> a >> b;
    fd >> h1 >> h2 >> h3 >> h4;

    for (int i = 0; i < 4; i++) fd >> P[i];
    for (int i = 0; i < 4; i++) fd >> A[i];

    int didz_pirmas = 0, didz_antras = 0;
    int didzPelnas = 0;

    skaiciavimas(a, b, h1, h2, h3, h4, P, A, didz_pirmas, didz_antras, didzPelnas);

    fr << didz_pirmas << "     " << didz_antras << endl;
    fr << "pelnas " << didzPelnas << " Lt";
	
	fr.close();
	fd.close();
    return 0;
}



