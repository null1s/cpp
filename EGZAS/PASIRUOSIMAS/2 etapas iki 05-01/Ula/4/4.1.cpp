#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

bool artinka(int x) 
{
return ((x>=32 && x<=33) || x==44 || x==46 || (x>=48 && x<=57) || x==63 || (x>=65 && x<=90) || (x>=97 && x<=122));
}

int main ()
{
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");

    int x;
    bool visitinka=true;

    while (fd>>x) 
	{
        if (!artinka(x)) 
		{
            fr<<"Neteisingas simbolis"<<endl;
            visitinka=false;
        }
    }

    if (visitinka) fr << "Teisingai" << endl;
    
    fd.close();
    fr.close();
    return 0;
}




