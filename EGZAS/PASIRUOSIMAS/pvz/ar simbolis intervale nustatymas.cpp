#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");
	char sim;
  fd.get(sim);
   if (sim>='a'&&sim<='z') fr <<"taip";
    fd.close();
    fr.close();
return 0;
}

