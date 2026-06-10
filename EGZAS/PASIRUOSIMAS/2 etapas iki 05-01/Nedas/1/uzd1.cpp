#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double skaiciavimas(double x1, double x2, double y1, double y2)
{
	double atkarpa = 0;
	
	atkarpa = double(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
	
	return atkarpa;
}

int main() {
    ifstream fd("duom1.txt");
    ofstream fr("rez1.txt");
  
  	double xA, yA, xB, yB, xC, yC;
  	double AB, BC, CA;
  	double plotas, p;
  	
  	fd >> xA >> yA >> xB >> yB >> xC >> yC;
  	
  	AB = skaiciavimas(xB, xA, yB, yA);
  	BC = skaiciavimas(xC, xB, yC, yB);
  	CA = skaiciavimas(xA, xC, yA, yC);
  	
  	p = (AB + BC + CA) / 2;
  	
  	plotas = double(sqrt(p * (p - AB) * (p - BC) * (p - CA)));
  	
  	fr << fixed << setprecision(2) << plotas;
    fd.close();
    fr.close();
    return 0;
}
