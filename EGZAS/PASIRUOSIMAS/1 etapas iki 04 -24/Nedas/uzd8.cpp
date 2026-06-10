#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	
	ifstream fd ("duom8.txt");
	ofstream fr ("rez8.txt");

	int n, metimai, suma = 0, metimas, didziausia_suma = 0, zaidejas;
	
	fd >> n;
	for (int i = 0 ; i < n ; i++)
	{
		fd >> metimai;
		bool stabdyti = false;
		for (int j = 0 ; j < metimai ; j++)
		{
			fd >> metimas;
			
			if (!stabdyti)
            {
                suma += metimas;

                if (metimas % 2 == 0)
                {
                    stabdyti = true;
                }
            }
		}
		
		
		if (suma > didziausia_suma)
		{
			didziausia_suma = suma;
			zaidejas = i + 1;
		}
		
		fr << i + 1 << " Zaidejas surinko " << suma << " tasku" << endl;
		suma = 0;
	}
	
	fr << "Zaidima laimejo " << zaidejas << " zaidejas, jis surinko " << didziausia_suma << " tasku";
	fd.close();
	fr.close();
    return 0;
}
