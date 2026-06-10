#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    int temp = 0, dienos = 0;
    double T[10], pokytis = 0, didz_pokytis = 0;
    bool zenklas;
    
    ifstream fd("duom5.txt");
    ofstream fr("rez5.txt");

    while (!fd.eof()) 
	{ 
        fd >> T[temp];
        temp++;
        dienos++;
    }
    
    for (int i = 0 ; i < dienos ; i++)
    {
    	zenklas = false;
    	fr << T[i] << endl;
		if (i != dienos - 1) fr << "    (";
    	
    	if (i != dienos - 1)
    	{
    		if((T[i+1] - T[i]) >= 0) fr << "+";
    		fr << (T[i+1] - T[i]) << ") " << endl;
    	}
    	
    	if (abs(T[i+1] - T[i]) > didz_pokytis && i != dienos - 1) 
		{
			didz_pokytis = abs(T[i+1] - T[i]);
			if ((T[i+1] - T[i]) < 0) zenklas = true;
		}
    	if(i != dienos - 1) pokytis = abs(T[i+1] - T[i]);
	}
	fr << "----------------" << endl << "Dienu skaicius: " << dienos << endl;
	fr << "Didziausias temperaturos pokytis: ";
	if (zenklas) fr << "-";
	else fr << "+";
	fr << didz_pokytis;
    return 0;
}
