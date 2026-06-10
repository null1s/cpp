#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;

struct produktai
{
	int baras_h;
	int a_h;
	int b_h;
};

void skaiciavimas (int a, int b, int & max, produktai A[4], int & I, int & II)
{
   	int pelnas=0;
   	
   	for (int x=0; x<=30; x++)
    {
    	for (int y=0; y<=30; y++)
    	{
            if (x * A[0].a_h + y * A[0].b_h <= A[0].baras_h &&
            x * A[1].a_h + y * A[1].b_h <= A[1].baras_h &&
            x * A[2].a_h + y * A[2].b_h <= A[2].baras_h &&
            x * A[3].a_h + y * A[3].b_h <= A[3].baras_h)
            {
            	pelnas=x*a+y*b;
            	if (pelnas>max)
            	{
        	        max=pelnas;
            		I=x;
            		II=y;
        	    }            	
			}
    	}
    }
}

int main ()
{
    produktai A[4];
    
	ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    
    int a, b, max=0, I, II;
    
    fd>>a>>b;
    for (int i=0; i<4; i++) fd>>A[i].baras_h;
    for (int i=0; i<4; i++) fd>>A[i].a_h;
    for (int i=0; i<4; i++) fd>>A[i].b_h;
    
    skaiciavimas(a,b,max,A,I,II);
    fr<<I<<" "<<II<<endl;
    fr<<"pelnas "<<max<<" Lt";
    
    fd.close();
    fr.close();
    return 0;
}


