#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct temperatura
{
	string diena; //txt dienos skirtingos
	string savaite; //visos savaites dienos
	int numeriai; //txt temperatura
	int laipsniai[24]; //temperatura sutvarkyta palei dienas
	int dregme;
	int kiekis; //temperaturos kiekis kiekvienos dienos
	double vid;
};

void skaitymas (temperatura A[24], int & n, int & sk)
{
	ifstream fd("Temp.txt");
	ifstream fe ("Dreg.csv");
	fd>>n;
	for (int i=0; i<n; i++)
	{
		fd>>A[i].diena>>A[i].numeriai;
	}
	
	string line;
    while(getline(fe,line)) sk++;
	fe.clear();
	fe.seekg(0);
	for(int i=0;i<sk;i++) 	 
	{
		 getline(fe,line);
		 stringstream ss(line);
		 getline(ss,A[i].savaite,';');	
		 ss>>A[i].dregme;
	}	
	
	int kiek=0;
	for (int i=0; i<sk; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (A[i].savaite==A[j].diena) 
			{
				A[i].laipsniai[kiek]=A[j].numeriai;			   
				kiek++;
				A[i].kiekis=kiek;
			}
			
			else if (A[i].savaite!=A[j].diena && kiek==0)
		    {
		    	A[i].kiekis=0;
		    }				
		}
		kiek=0;
	}
	
	fd.close();
	fe.close();	
}

void rikiavimas (int laipsniai[], int n)
{
	int x; 
    int y;
    for (int i=0; i<n-1; i++)
    {
        x=i;
        for (int j=i+1; j<n; j++) if (laipsniai[j]<laipsniai[x]) x=j;
        
        {
        y=laipsniai[i];
        laipsniai[i]=laipsniai[x];
        laipsniai[x]=y;
        }
    }
}

double vidurkis (temperatura A[24], int n, int i)
{
	double vid=0;
	int suma=0;
	for (int j=0; j<n; j++)
	{
		suma+=A[i].laipsniai[j];
	}
	vid=(double)suma/n;
	if (n==0) vid=0;
	return vid;
}

void pirminiai (int laipsniai[24], int & n)
{
	int kiek=0;
	for (int i=0; i<n; i++)
	{
		for (int j=1; j<100; j++)
		{
	    	if (laipsniai[i]%j==0) kiek++;		
		}
		
		if (kiek<=2 ||  laipsniai[i]==0)
		{
			for(int j=i; j<n; j++) laipsniai[j]=laipsniai[j+1];
        	n--; i--;
		}
		
		kiek=0;
	}
}

int main()
{
	ofstream fr("rez.txt");
	temperatura A[25];
	int n, sk=0;

	skaitymas(A,n,sk);
    //rikiavimas
    for (int i=0; i<sk; i++)
    {
    	rikiavimas(A[i].laipsniai,A[i].kiekis);
	}
    //vidurkis
    for (int i=0; i<sk; i++)
    {
    	A[i].vid=vidurkis(A,A[i].kiekis,i);  		
	}
    //isvedam surikiuotus laipsnius
	for (int i=0; i<sk; i++)
	{
		fr<<A[i].savaite<<" ";
		for (int j=0; j<A[i].kiekis; j++)
		{
			fr<<A[i].laipsniai[j]<<" ";
		}
		fr<<endl;
	}
	fr<<endl;
    //isvedam vidurki
    for (int i=0; i<sk; i++)
    {
    	fr<<A[i].savaite<<" "<<A[i].vid<<endl;
	}
	fr<<endl;
	//pirminiai
	for (int i=0; i<sk; i++)
	{
		pirminiai(A[i].laipsniai,A[i].kiekis);
	}
	//isvedam pirminius
	for (int i=0; i<sk; i++)
	{
		fr<<A[i].savaite<<" ";
		for (int j=0; j<A[i].kiekis; j++)
		{
			fr<<A[i].laipsniai[j]<<" ";
		}
		fr<<endl;
	}
	fr<<endl;
    
    
    fr.close();
return 0;
}
