#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	
	ifstream fd ("duom7.txt");
	ofstream fr ("rez7.txt");
	int n, gn, gs, savikaina;
	int didziausias;
	int pjaustykle = 0, virdulys = 0, mikseris = 0, plaktuve = 0;
	fd >> n;
	
	for (int i = 0 ; i < n ; i++)
	{
		fd >> gn >> gs;
		
		for (int j = 0 ; j < gs ; j++)
		{
			fd >> savikaina;
			if (gn == 1) pjaustykle = pjaustykle + savikaina;
			if (gn == 2) virdulys = virdulys + savikaina;
			if (gn == 3) mikseris = mikseris + savikaina;
			if (gn == 4) plaktuve = plaktuve + savikaina;
		}
	}
	
	fr << "Pjaustykliu: " << pjaustykle << " Eur" << endl;
	fr << "Virduliu: " << virdulys << " Eur" << endl;
	fr << "Mikseriu: " << mikseris << " Eur" << endl;
	fr << "Plaktuviu: " << plaktuve << " Eur" << endl;
	
	didziausias = max(max(pjaustykle, virdulys), max(mikseris, plaktuve));
	if (pjaustykle == didziausias) fr << "Pjaustykliu pagaminta didziausiai sumai";
	else if (virdulys == didziausias) fr << "Virduliu pagaminta didziausiai sumai";
	else if (mikseris == didziausias) fr << "Mikseriu pagaminta didziausiai sumai";
	else if (plaktuve == didziausias) fr << "Plaktuviu pagaminta didziausiai sumai";
	fd.close();
	fr.close();
    return 0;
}
