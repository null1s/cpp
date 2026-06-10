//Byloje nurodytas atliktø matavimø kiekis ir iðvardinti visi matavimai (double).
//Suraðykite á kità bylà visus matavimo rezultatus didesnius uþ dvigubà vidutiná
//matavimø paskaièiavimà, iðdëstytus didëjimo tvarka.
// 1. paraðykite skaitymo funkcijà
// 2. paraðykite paprastà funkcijà vidurkiui skaièiuoti
// 3. paraðykite loginæ funkcijà nustatanèià ar matavimas atitinka sàlygà
// 4. sudarykite naujà masyvà sàlygà atitinkanèiams matavimams saugoti
// 5. paraðykite rikiavimo funkcijà
// 6. paraðykite spausdinmo funkcijà
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

//--------funkcija nuskaitanti pradinius duomenis
void skaitymas(int & n, double mat[])
{
	ifstream fd("duom.txt");
	
	fd>> n;
	
	for(int i=1; i<=n; i++)
	{
		fd>> mat[i];
	}
	
	
	fd.close();
}

//-------funkcija vidurkiui skaièiuoti
double vidurkis(int n, double mat[])
{
	int sum=0;
	double vid=0;
	for(int i=1; i<=n; i++)
	{
		sum+=mat[i];
	}
	
	vid=(double)sum/n;
	
	return vid;
}

//------funkcija patikrinanti ar narys didesnis uþ dvigubà vidurká
bool patikrinimas(double a, double vid)
{
	bool ats;
	if(a > vid*2) ats=true;
	         else ats=false;
	
	return ats;
	
}

//----masyvo rikiavimo funkcija
void rikiavimas(int j, double mat2[])
{
	
	int laik=0, t=0;
	
	for(int i=1; i<=j-1; i++)
	{
		laik=i;
		for(int z=i+1; z<=j; z++)
		{
			if(mat2[z]<mat2[laik]) laik=z;
		}
		 t=mat2[laik];
		 mat2[laik]=mat2[i];
		 mat2[i]=t;
	}
	
}

//----spausdinimo funkcija
void rasymas(int n, double mat[])
{
	ofstream fr("rez.txt");
	
	for(int i=1; i<=n; i++)
	{
		fr<< mat[i]<<" ";
	}
	
	fr.close();
}



int main()
{
	int n, j=0;
	double mat[100], vidv=0, mat2[100];
	
	
	skaitymas(n, mat);
	vidv = vidurkis(n, mat);
	
	for(int i=1; i<=n; i++)  //naujo masyvo atitinkanèio sàlygà kurimas
	{
		if(patikrinimas(mat[i], vidv))
		{
			j++;  //naujo indekso kuriamam naujam masyvui ávedimas
			mat2[j]=mat[i];
		}
	}
	
	
	rikiavimas(j, mat2);
	
	
	rasymas(j, mat2);
	
	
	

	
return 0;
}

