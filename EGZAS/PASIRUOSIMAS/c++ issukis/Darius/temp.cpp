#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
struct temp{
	string t;
	int t1;
};
	

int main()
{
int n=0, C[2000], kk=0, p=0, a=0, t=0, k=0, p1=0, s1=0, s2=0;
double avg[10];
temp A[170], B[170];
ifstream fd ("temp.txt");
ofstream fr ("rez.txt");
fd>>n;
for(int i=0; i<n; i++){
	fd>>A[i].t>>A[i].t1;
	if (A[i].t=="Pirmadienis") p++;
	if (A[i].t=="Antradienis") a++;
	if (A[i].t=="Treciadienis") t++;
	if (A[i].t=="Ketvirtadienis") k++;
	if (A[i].t=="Penktadienis") p1++;
	if (A[i].t=="Sestadienis") s1++;
	if (A[i].t=="Sekmadienis") s2++;
}
int t1=kk, t2=p, t3=p+a, t4=p+a+t, t5=p+a+t+k, t6=p+a+t+k+p1, t7=p+a+t+k+p1+s1, t8=p+a+t+k+p1+s1+s2;
for(int i=0; i<n; i++){
	
	if (A[i].t=="Pirmadienis"){
	B[t1].t=A[i].t;
	B[t1].t1=A[i].t1;
	t1++;
}

	if (A[i].t=="Antradienis"){
	B[t2].t=A[i].t;
	B[t2].t1=A[i].t1;
	t2++;
}
	if (A[i].t=="Treciadienis"){
	B[t3].t=A[i].t;
	B[t3].t1=A[i].t1;
	t3++;
}
	if (A[i].t=="Ketvirtadienis"){
	B[t4].t=A[i].t;
	B[t4].t1=A[i].t1;
	t4++;
}
		if (A[i].t=="Penktadienis"){
	B[t5].t=A[i].t;
	B[t5].t1=A[i].t1;
	t5++;
}
		if (A[i].t=="Sestadienis"){
	B[t6].t=A[i].t;
	B[t6].t1=A[i].t1;
	t6++;
}
		if (A[i].t=="Sekmadienis"){
	B[t7].t=A[i].t;
	B[t7].t1=A[i].t1;
	t7++;
}
}


int pirm=0;
for(int i=0; i<n; i++){
	for(int j=1; j<=B[i].t1; j++){
	if (B[i].t1%j==0) pirm++;
	}
	if (pirm>2) fr<<B[i].t<<" "<<B[i].t1<<endl;
	pirm=0;
}


	for(int i=0; i<n; i++){
		if (p>0) if (i<t2) avg[1]+=B[i].t1;
		if (a>0) if (i<t3) avg[2]+=B[i].t1;
		if (t>0) if (i<t4) avg[3]+=B[i].t1;
		if (k>0) if (i<t5) avg[4]+=B[i].t1;
		if (p1>0) if (i<t6) avg[5]+=B[i].t1;
		if (s1>0) if (i<t7) avg[6]+=B[i].t1;
		if (s2>0) if (i<t8) avg[7]+=B[i].t1;
	}
		fr<<endl<<"Vidurkiai: "<<endl;
	    if (p>0) fr<<"Pirmadienis "<<avg[1]/p<<endl;
		if (a>0) fr<<"Antradienis "<<avg[2]/a<<endl;
		if (t>0) fr<<"Treciadienis "<<avg[3]/t<<endl;
		if (k>0) fr<<"Ketvirtadienis "<<avg[4]/k<<endl;
		if (p1>0) fr<<"Penktadienis "<<avg[5]/p1<<endl;
		if (s1>0) fr<<"Sestadienis "<<avg[6]<<endl;
		if (s2>0) fr<<"Sekmadienis "<<avg[7]/s2<<endl;

	
	
fd.close();
fr.close();


return 0;
}

