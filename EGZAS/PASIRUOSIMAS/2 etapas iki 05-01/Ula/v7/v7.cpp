#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;

struct trupmenos
{
    int sveika[2];
    int skaitiklis[2];
    int vardiklis[2];
    int veiksmu_sk[2];
    int veiksmu_v[2];
};

void prastinimas(int &skai,int &var)
{
    int daliklis=1,min;

    if(skai<var)min=skai;
    else min=var;

    for(int i=1;i<=min;i++)
    {
        if(skai%i==0 && var%i==0)
            daliklis=i;
    }

    skai=skai/daliklis;
    var=var/daliklis;
}

void veiksmai(trupmenos A[100],int n)
{
    for(int i=0;i<n;i++)
    {
        int sk1,sk2;

        sk1=A[i].sveika[0]*A[i].vardiklis[0]+A[i].skaitiklis[0];
        sk2=A[i].sveika[1]*A[i].vardiklis[1]+A[i].skaitiklis[1];

        // suma
        A[i].veiksmu_sk[0]=sk1*A[i].vardiklis[1]+sk2*A[i].vardiklis[0];
        A[i].veiksmu_v[0]=A[i].vardiklis[0]*A[i].vardiklis[1];

        prastinimas(A[i].veiksmu_sk[0],A[i].veiksmu_v[0]);

        // skirtumas
        A[i].veiksmu_sk[1]=sk1*A[i].vardiklis[1]-sk2*A[i].vardiklis[0];
        A[i].veiksmu_v[1]=A[i].vardiklis[0]*A[i].vardiklis[1];

        prastinimas(A[i].veiksmu_sk[1],A[i].veiksmu_v[1]);
    }
}

void spausdinimas(trupmenos A[100],int n)
{
    ofstream fr("rez.txt");

    fr<<"----------------------------------------------------------"<<endl;
    fr<<"T1         T2         Suma         Skirtumas         "<<endl;
    fr<<"----------------------------------------------------------"<<endl;

    for(int i=0;i<n;i++)
    {
        // T1
        if(A[i].sveika[0]==0) fr<<"   "<<A[i].skaitiklis[0]<<"/"<<A[i].vardiklis[0]<<"     ";
        else fr<<A[i].sveika[0]<<" "<<A[i].skaitiklis[0]<<"/"<<A[i].vardiklis[0]<<"     ";

        // T2
        if(A[i].sveika[1]==0) fr<<"   "<<A[i].skaitiklis[1]<<"/"<<A[i].vardiklis[1]<<"     ";
        else fr<<A[i].sveika[1]<<" "<<A[i].skaitiklis[1]<<"/"<<A[i].vardiklis[1]<<"     ";

        // SUMA
        if(A[i].veiksmu_sk[0]==0) fr<<"     ";
        else if(A[i].veiksmu_sk[0]%A[i].veiksmu_v[0]==0) fr<<A[i].veiksmu_sk[0]/A[i].veiksmu_v[0]<<"     ";
        else
        {
            int sk=A[i].veiksmu_sk[0];
            int v=A[i].veiksmu_v[0];

            if(sk/v!=0)
                fr<<sk/v<<" "<<abs(sk%v)<<"/"<<v<<"     ";
            else
                fr<<sk<<"/"<<v<<"     ";
        } 

        // SKIRTUMAS
        if(A[i].veiksmu_sk[1]==0) fr<<"     ";
        else if(A[i].veiksmu_sk[1]%A[i].veiksmu_v[1]==0) fr<<A[i].veiksmu_sk[1]/A[i].veiksmu_v[1]<<"     ";
        else
        {
            int sk=A[i].veiksmu_sk[1];
            int v=A[i].veiksmu_v[1];

            if(sk/v!=0)
                fr<<sk/v<<" "<<abs(sk%v)<<"/"<<v;
            else
                fr<<sk<<"/"<<v;
        }
        fr<<endl;
    }
    fr.close();
}

int main()
{
    trupmenos A[100];
    ifstream fd("duom.txt");

    int n;
    fd>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            fd>>A[i].sveika[j]>>A[i].skaitiklis[j]>>A[i].vardiklis[j];
        }
    }

    veiksmai(A,n);
    spausdinimas(A,n);

    fd.close();
    return 0;
}

