#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

struct mokinys
{
	string vardas;
	string mok_id;
	string mok_kl;
	string D[10];
	int dal_sk=0;
	int kodas;
	int egz = 1;
};

//neteisinga(A[i].kodas)

int main()
{
	string line;
	ifstream fd ("duom.txt");
	ofstream fr ("rez.txt");

	int n;
	fd >> n;
	fd.ignore(); // nukelia eilute
	mokinys A[500];
///---------------------------nuskaitome pirma dali
	for (int i = 0 ; i < n ; i++)
	{
		getline (fd,line); // parenka eilute
		stringstream ss (line); // sukuria komanda eilutes duomenims skaityti
		getline(ss, A[i].vardas, ';'); // nuskaito duomenis iki ;
		getline(ss, A[i].mok_id, ';'); // nuskaito duomenis iki ;
		ss >> A[i].mok_kl; // nuskaito kas liko
	}
////----------------------nuskaitome antra failo dali
while(!fd.eof())
{
	string n_kodas;
	int x;
	getline (fd,line);
	stringstream ss (line);
	getline(ss, n_kodas, ';');
	for(int i=0;i<n;i++)
	{
		if(n_kodas==A[i].mok_id) x=i;
	}
	while(getline(ss, line, ';'))
	{
		A[x].D[A[x].dal_sk]=line;
		A[x].dal_sk++;
	}
}
//-------------spausdinu visa struktura
for(int i=0;i<n;i++)
{
	fr<<A[i].vardas<<" "<<A[i].mok_id<<" "<<A[i].mok_kl<<" "<<A[i].dal_sk<<" " ;
	for(int j=0;j<A[i].dal_sk;j++)
	{
		fr<<A[i].D[j]<<" ";
	}
	fr<<endl;
}
////------------- skaiciuoja kiek mokiniu mokosi klasese

	int klase_a = 0;
	int klase_b = 0;
	int klase_c = 0;

	for (int i = 0 ; i < n ; i++) // nuskaito kiek mokiniu kokioj klasej
	{
		if(A[i].mok_kl == "12a")	{			klase_a = klase_a + 1;		}
		if(A[i].mok_kl == "12b")	{			klase_b = klase_b + 1;		}
		if(A[i].mok_kl == "12c")	{			klase_c = klase_c + 1;		}
	}
	fr << klase_a << " " << klase_b << " " << klase_c;
////----------------------------sudeda 4 saiciu koda
	for (int i = 0 ; i < n ; i++)
	{
		string s = A[i].mok_id;
		s.erase(0, s.size() - 4); // iðtrina nuo 0 iki paskutiniø 4 simboliø
		int skaicius = stoi(s);
		A[i].kodas = skaicius%10 + skaicius/10%10 + skaicius/100%10 + skaicius/1000%10;
		cout << A[i].kodas << endl;
			}



    fd.close();
    fr.close();
return 0;
}
















