#include<fstream>
#include<iostream>
using namespace std;
// ar galima taip spresti, jei ivedus kitus duomenis butu neteisinga??
// t.y. ar reikia kaip olimpiadoje, jog su ivairiais variantais veiktu
struct produktai
{
	int numeris;
	int skaicius;
	int savikainos[100];
};

int main()
{
	produktai A[100];
	ifstream fr ("duom.txt");
	ofstream fd ("rez.txt");
	
	int n, psuma=0, vsuma=0, msuma=0, plsuma=0, did=0;
	fr>>n;
	
	for (int i=0; i<n; i++)
	{
		fr>>A[i].numeris>>A[i].skaicius;
		for (int j=0; j<A[i].skaicius; j++)
		{
			fr>>A[i].savikainos[j];
		}
	}
	
    for (int i=0; i<n; i++)
    {
    	if (A[i].numeris==1)
    	{
    		for (int j=0; j<A[i].skaicius; j++)
    		{
    			psuma=A[i].savikainos[j]+psuma;
			}
		}
		
		if (A[i].numeris==2)
    	{
    		for (int j=0; j<A[i].skaicius; j++)
    		{
    			vsuma=A[i].savikainos[j]+vsuma;
			}
		}
		
		if (A[i].numeris==3)
    	{
    		for (int j=0; j<A[i].skaicius; j++)
    		{
    			msuma=A[i].savikainos[j]+msuma;
			}
		}
		
		if (A[i].numeris==4)
    	{
    		for (int j=0; j<A[i].skaicius; j++)
    		{
    			plsuma=A[i].savikainos[j]+plsuma;
			}
		}
		
		if (psuma>did) did=psuma;
		else if (vsuma>did) did=vsuma;
		else if (msuma>did) did=msuma;
		else if (plsuma>did) did=plsuma;
	}
	
	fd<<"Pjaustykliu: "<<psuma<<endl;
	fd<<"Virduliu: "<<vsuma<<endl;
	fd<<"Mikseriu: "<<msuma<<endl;
	fd<<"Plaktuviu: "<<plsuma<<endl;
	
	
	if (did==psuma) fd<<"Pjaustykliu"; 
	else if (did==vsuma) fd<<"Virduliu"; 
	else if (did==msuma) fd<<"Mikseriu";
	else if (did==plsuma) fd<<"Plaktuviu";
	fd<<" pagaminta didziausiai sumai";
	
	fr.close();
    fd.close();
return 0; 
}
