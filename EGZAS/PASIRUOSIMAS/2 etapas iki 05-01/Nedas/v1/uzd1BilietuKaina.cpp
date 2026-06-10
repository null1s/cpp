#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int vietoskaina(int eile)
{
	int kaina;
	
    if (eile < 3) kaina = 100;
    else if (eile > 4) kaina = 40;
    else kaina = 70;
    
    return kaina;
}

void skaiciavimas(ifstream & fd, int eiles, int kedes, int & suma, double & vidurkis)
{
    int vieta, kiekis = 0, kaina;
    suma = 0;

    for (int i = 0 ; i < eiles ; i++)
    {
        kaina = vietoskaina(i + 1);

        for (int j = 0 ; j < kedes ; j++)
        {
            fd >> vieta;

            if (vieta == 1)
            {
                suma = suma + kaina;
                kiekis++;
            }
        }
    }

    vidurkis = (double)suma / kiekis;
}

int main()
{
    ifstream fd("duom1BilietuKaina.txt");
    ofstream fr("rez1BilietuKaina.txt");

    int eiles, kedes, suma;
    double vidurkis;

    fd >> eiles >> kedes;

    skaiciavimas(fd, eiles, kedes, suma, vidurkis);

    fr << suma << " ";
    fr << fixed << setprecision(2) << vidurkis;

	fr.close();
	fd.close();
    return 0;
}
