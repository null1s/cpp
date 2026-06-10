#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void skaiciavimas1(int papildomi, int n, int a, int b, int x, int y, int z, double & suma, double & mokiniu_suma, double & mokytoju_suma)
{
	n = n + papildomi;
	
	if(n < 10)
	{
		mokiniu_suma = a * x;
		mokytoju_suma = b * x;
		suma = mokiniu_suma + mokytoju_suma;
		if(papildomi == 4) suma = suma + papildomi * x;
	}
	else if (n > 10 && n < 20)
	{
		mokiniu_suma = a * y;
		mokytoju_suma = b * y;
		suma = mokiniu_suma + mokytoju_suma;
		if(papildomi == 4) suma = suma + papildomi * y;
	}
	else
	{
		mokiniu_suma = a * z;
		mokytoju_suma = b * z;
		suma = mokiniu_suma + mokytoju_suma;
		if(papildomi == 4) suma = suma + papildomi * z;
	}
}

int main() 
{
    ifstream fd("duom3.txt");
	ofstream fr("rez3.txt");

	int n, a, b, x, y, z, papildomi = 0;
	double suma = 0, mokiniu_suma = 0, mokytoju_suma = 0;
	fd >> n >> a >> b >> x >> y >> z;
	
	
	skaiciavimas1(papildomi, n, a, b, x, y, z, suma, mokiniu_suma, mokytoju_suma);
	fr << fixed << setprecision(2) << suma << " " << mokiniu_suma << " " << mokytoju_suma << endl;
	papildomi = 4;
	skaiciavimas1(papildomi, n, a, b, x, y, z, suma, mokiniu_suma, mokytoju_suma);
	fr << fixed << setprecision(2) << suma << endl << suma / n;
    fd.close();
    fr.close();
    return 0;
}
