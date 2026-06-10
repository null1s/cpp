#include<iostream>
#include<fstream>

using namespace std;

int main()
{ 

	ifstream fd ("2.txt");
     ofstream fr ("rez.txt");
    
    int n, ben=0;
    cout<<"Surasyti duomenis"<<endl;
    cin>>n;
    for (int i=0; i<n; i++){
    int a, b, sum=0;
    cin>>a;
    for (int j=0; j<a; j++){
    cin>>b;
    sum += b;
}
    cout<<"atsakymas:"<<sum<<endl;
    ben+=sum;
}
cout<<"atsakymas:"<<ben<<endl;

	 fd.close();
 fr.close();
return 0;
}

