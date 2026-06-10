#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() 
{
	
	ifstream fd ("duom6.txt");
	ofstream fr ("rez6.txt");

	long long skaicius;
	int sk, poz = 0, A[100], skaitmuo, suma = 0;
	
	fd >> skaicius;
	
    while (skaicius > 0) 
	{
        sk = skaicius % 10;  
        A[poz] = sk;
        poz++;
        skaicius /= 10;
    }
	
	for (int i = 1 ; i < poz ; i += 2)
	{
		skaitmuo = A[i] * 2;
		if (skaitmuo > 9)
		{
			A[i] = (skaitmuo / 10) + (skaitmuo % 10);
		}
		else
    	{
        A[i] = skaitmuo;
    	}
	}
	
	for (int i = 0 ; i < poz ; i++)
	{
		suma = suma + A[i];
	}
	
	if (suma % 10 == 0) fr << "Teisingas";
	else fr << "Neteisingas";
	fd.close();
	fr.close();
    return 0;
}
