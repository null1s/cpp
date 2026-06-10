#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
double simbol(double a) {
bool t;
if (a>=32&&a<=122) t=true;
else t=false;
return t;
}
int main() {
    double a=0, neteis=0;
    ifstream fd ("duom.txt");
    ofstream fr ("rez.txt");

while(!fd.eof()){
fd>>a;
if (simbol(a)==false){
fr<<a<<" yra neteisingas simbolis"<<endl;
neteis++;
}
}
if (neteis==0) fr<<"Teisingai";
    fd.close();
    fr.close();
    return 0;
}