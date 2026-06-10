#include<fstream>
#include<iostream>
using namespace std;

void skaitymas (int & n1, int & n2, int & sk, int A[100])
{
	ifstream fd("duom.txt");
	fd>>n1>>n2>>sk;
	for (int i=0; i<sk; i++)
	{
		fd>>A[i];
	}
	fd.close();
}

void dydziai ()
{
	
}

void spausdinimas ()
{
	ofstream fr("rez.txt");
	
	fr.close();
}

int main()
{
	//n1 - 1 kg ; n2 - 2 kg
	int n1, n2, sk, A[100], skaicius=0, n_1=0, n_2=0;
	
	skaitymas(n1,n2,sk,A);
	
	for (int i=0; i<sk; i++)
	{
		if (n1>0 && n2>0)
		{
			if (A[i]>=2)
		    {
		    	if (A[i]%2==0)
		    	{
		    		n2=n2-(A[i]/2);
		    		n_2++;
		    		skaicius+=A[i]/2;
		    		
		    	/*/	cout<<n2<<" "<<n_2;
		    		cout<<skaicius<<" ";
		    		cout<<endl;/*/
				}
			    else if (A[i]>2)
			    {
		    	n1=n1-(A[i]-n2);
		    	n_1++;
		    	n2=n2-(A[i]/2);
		    	n_2++;
		    	skaicius+=A[i]/2+A[i]-n2;
		    	
		    /*/	cout<<n2<<" "<<n_2;
		    	cout<<skaicius<<" ";
		    	cout<<n1<<" "<<n_1;
		    	cout<<endl;/*/
	        	}
	        }
	        
	    	else if (A[i]<2 && A[i]>0)
	    	{
			n1=n1-A[i];
			n_1++;
			skaicius+=n1-A[i];
			
		    cout<<skaicius<<" ";
		    cout<<n1<<" "<<n_1;
		    cout<<endl;
	    	}	
	    }
    }
/*/	skaicius=0;
	skaicius=n_1+n_2;/*/
/*/	cout<<n_1<<" "<<n_2<<endl;
	cout<<skaicius<<endl;/*/
	
	
	
	
return 0;
}
