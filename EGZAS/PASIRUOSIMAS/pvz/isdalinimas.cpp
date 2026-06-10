//Turiu suma reikia i6dalinti i 5 3 1 monetas
#include<fstream>
#include<iostream>
using namespace std;

void sk(int n, int & po_5, int & po_3, int & po_1)
{
	int liek;
	po_5 = n / 5;
	liek = n % 5;
	po_3 = liek / 3;
	po_1 = liek % 3;
}

int main()
{
	int n, po_5, po_3, po_1;
	ifstream fd ("duom.txt");
	ofstream fr ("Rez.txt");
	
	fd >> n;
	sk(n, po_5, po_3, po_1);
	fr <<"5 " << po_5 << endl;
	fr << "3 " << po_3 << endl;
	fr << "1 " << po_1;
	
	fd.close();
	fr.close();
	
return 0;
}

