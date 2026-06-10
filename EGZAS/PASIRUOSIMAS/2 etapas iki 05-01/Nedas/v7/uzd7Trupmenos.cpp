#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int dbd(int a, int b)
{
	while(b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void sudetis(int sv1, int sk1, int vd1, int sv2, int sk2, int vd2, int & sk3, int & vd3)
{
	int a = sv1 * vd1 + sk1;
	int b = sv2 * vd2 + sk2;
	vd3 = vd1 * vd2;
	sk3 = a * vd2 + b * vd1;
} 

void atimtis(int sv1, int sk1, int vd1, int sv2, int sk2, int vd2, int & sk3, int & vd3)
{
	int a = sv1 * vd1 + sk1;
	int b = sv2 * vd2 + sk2;
	vd3 = vd1 * vd2;
	sk3 = a * vd2 - b * vd1;
}

void prastinimas(int & sv3, int & sk3, int & vd3)
{
	int k = dbd(abs(sk3), vd3);
	sk3 = sk3 / k;
	vd3 = vd3 / k;

	sv3 = sk3 / vd3;
	sk3 = sk3 % vd3;
}

void isvedimas(ofstream & fr,int sv3, int sk3, int vd3)
{
	if(sv3 != 0) fr << sv3;
	if(sk3 != 0) fr << " " << sk3 << "/";
	if(sk3 != 0) fr << vd3 << "              ";
}

int main()
{
    ifstream fd("duom7Trupmenos.txt");
    ofstream fr("rez7.txt");

	int n;
	int sv1, sv2, sk1, sk2, vd1, vd2, sv3 = 0, sk3 = 0, vd3 = 0;
	
	fd >> n;
	
	fr << "---------------------------------------------------------" << endl;
	fr << "  T1              T2            Suma           Skirtumas" << endl;
	fr << "---------------------------------------------------------" << endl;
	
	for(int i = 0 ; i < n ; i++) 
	{
		fd >> sv1 >> sk1 >> vd1 >> sv2 >> sk2 >> vd2;
		if(sv1 !=0) fr << sv1;
		fr << " " << sk1 << "/" << vd1 << "          ";
		if(sv2 != 0) fr << sv2;
		fr << " " << sk2 << "/" << vd2 << "          ";
		
		sudetis(sv1, sk1, vd1, sv2, sk2, vd2, sk3, vd3);
		prastinimas(sv3, sk3, vd3);
		isvedimas(fr, sv3, sk3, vd3);
		atimtis(sv1, sk1, vd1, sv2, sk2, vd2, sk3, vd3);
		prastinimas(sv3, sk3, vd3);
		isvedimas(fr, sv3, sk3, vd3);
		fr << endl;
	}
	
	
    fd.close();
    fr.close();
    return 0;
}
