#include <iostream>
#include <fstream>
using namespace std;

struct diena
{
    string pav;
    int temp[100];
    int suma;
    int temp_skaicius;
    int dregme;
};

void skaitymas(diena dienos[], int & kiek_dienu)
{
    ifstream fd("temp.txt");

    string pav;
    int n, temp;

    fd >> n;

    for (int i = 0 ; i < n; i++)
    {
        fd >> pav >> temp;

        bool yra = false;
        int vieta;

        for (int j = 0 ; j < kiek_dienu; j++)
        {
            if (pav == dienos[j].pav)
            {
                yra = true;
                vieta = j;
            }
        }

        if (yra == false)
        {
            dienos[kiek_dienu].pav = pav;
            dienos[kiek_dienu].temp[0] = temp;
            dienos[kiek_dienu].suma = temp;
            dienos[kiek_dienu].temp_skaicius = 1;

            kiek_dienu++;
        }
        else
        {
            dienos[vieta].suma = dienos[vieta].suma + temp;
            dienos[vieta].temp[dienos[vieta].temp_skaicius] = temp;
            dienos[vieta].temp_skaicius++;
        }
    }

    fd.close();
}

void rikiavimas(diena dienos[], int kiek_dienu)
{
	int laikinas;
	
    for (int i = 0 ; i < kiek_dienu; i++)
    {
        for (int j = 0 ; j < dienos[i].temp_skaicius - 1; j++)
        {
            for (int k = j + 1 ; k < dienos[i].temp_skaicius; k++)
            {
                if (dienos[i].temp[j] > dienos[i].temp[k])
                {
                	laikinas = dienos[i].temp[j];
                	dienos[i].temp[j] = dienos[i].temp[k];
                	dienos[i].temp[k] = laikinas;               		
				}
            }
        }
    }
}

double vidurkio_skaiciavimas(diena dienos[], int vieta)
{
	return (double)dienos[vieta].suma / dienos[vieta].temp_skaicius;
}

bool pirminis (int skaicius)
{
	int dalikliai = 0;
	
	if (skaicius <= 1) return false;
	
	for (int i = 1 ; i <= skaicius ; i++)
	{
		if(skaicius % i == 0) dalikliai++;
	}
	
	if (dalikliai == 2) return true;
	else return false;
}
void salinimas(diena dienos[], int kiek_dienu)
{
	for (int i = 0 ; i < kiek_dienu; i++)
    {
        for (int j = 0 ; j < dienos[i].temp_skaicius ; j++)
        {
            if (pirminis(dienos[i].temp[j]))
            {
            	for (int k = j ; k < dienos[i].temp_skaicius - 1 ; k++)
            	{
            		dienos[i].temp[k] = dienos[i].temp[k + 1];
				}
				dienos[i].temp_skaicius--;
				j--;
			}
        }
    }
}

void dregmes_skaitymas(diena dienos[], int kiek_dienu)
{
    ifstream fd("dreg.csv");
    
    string pav;
    int skaicius;
    int vieta = 0;
    
    while (getline(fd, pav, ';'))
    {
        fd >> skaicius;
        fd.ignore();

        while (skaicius >= 100)
        {
            skaicius = skaicius / 10;
        }

        dienos[vieta].dregme = skaicius;
        vieta++;
    }
    fd.close();
}

int main()
{
    ofstream fr("rez.txt");

    diena dienos[7];
    int kiek_dienu = 0;

    skaitymas(dienos, kiek_dienu);
    rikiavimas(dienos, kiek_dienu);
	
	for (int i = 0 ; i < kiek_dienu; i++)
	{
   		fr << dienos[i].pav << " temperaturos: ";

    	for (int j = 0 ; j < dienos[i].temp_skaicius; j++)
    	{
        	fr << dienos[i].temp[j] << " ";
    	}
    	fr << endl;
	}
	
	fr << endl; 
	
	for(int i = 0 ; i < kiek_dienu ; i++) 
	{
		fr << dienos[i].pav << " vidurkis: " << vidurkio_skaiciavimas(dienos, i) << endl;
	}
    
    salinimas(dienos, kiek_dienu);
    fr << endl << "Po salinimo:" << endl << endl;
    
    for (int i = 0 ; i < kiek_dienu; i++)
	{
   		fr << dienos[i].pav << " temperaturos: ";

    	for (int j = 0 ; j < dienos[i].temp_skaicius; j++)
    	{
        	fr << dienos[i].temp[j] << " ";
    	}
    	fr << endl;
	}
	
	dregmes_skaitymas(dienos, kiek_dienu);
	fr << endl << "Po dregmes iterpimo: " << endl << endl;
	
	for (int i = 0 ; i < kiek_dienu; i++)
	{
		fr << dienos[i].pav << " temperaturos: ";
		
    	for (int j = 0 ; j < dienos[i].temp_skaicius; j++)
    	{
    		fr << dienos[i].temp[j] << " ";
        	if(dienos[i].temp[j] < 0)
        	{
        		fr << "(" << dienos[i].dregme << ") ";
			}
    	}
    	fr << endl;
	}
    fr.close();
    return 0;
}
