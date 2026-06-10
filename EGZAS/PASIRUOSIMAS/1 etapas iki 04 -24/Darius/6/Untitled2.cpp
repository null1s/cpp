#include<iostream>
#include<fstream>
using namespace std;
int main()
{
int n=0;
double temp[1000], sk[1000], max=0;
ifstream fd("duom.txt");
ofstream fr("rez.txt");
while(!fd.eof())
    {
    	fd>>temp[n];
    	n++;
	}
for(int i=0; i<n; i++){
	if (i<n-1) sk[i]=temp[i+1]-temp[i];
	if (i==0) max=sk[i];
	if (sk[i]>max) max=sk[i];
}
for(int i=0; i<n; i++){
	fr<<temp[i]<<endl;
	if (i<n-1) fr<<sk[i]<<endl;
	cout<<temp[i];
}
fr<<"Dienu skacius"<<n<<endl;
fr<<"Didziausias temperaturos pokytis "<<max<<endl;

fd.close();
fr.close();
}

