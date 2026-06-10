#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	
	ifstream fd ("duom9.txt");
	ofstream fr ("rez9.txt");

	int a, b;
	int A[100], dalikliai, didz_dalikliai = 0, poz = 0, didz_sk;
	fd >> a >> b;
	
	for(int i = a ; i <= b ; i++)
	{
		dalikliai = 0;
		for(int j = 1 ; j <= i  ; j++)
		{
			if (i % j == 0) 
			{
				dalikliai++;
			}
		}
		if (dalikliai > didz_dalikliai)
		{
			didz_dalikliai = dalikliai;
			didz_sk = i;
		}
	}
	
	fr << "Skaicius " << didz_sk << " turi daugiausia dalikliu " << didz_dalikliai << endl;
	for (int i = 1 ; i <= didz_sk ; i++)
	{
		if (didz_sk % i == 0) fr << i << " ";
	}

	fd.close();
	fr.close();
    return 0;
}
