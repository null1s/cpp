#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
	int sk, s;
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
    while(!fd.eof())
    {
    	fd>>sk;
    	s +=sk;
	}
	fr<<s;
    fd.close();
    fr.close();
return 0;
}

