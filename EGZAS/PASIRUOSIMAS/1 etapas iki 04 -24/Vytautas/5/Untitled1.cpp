#include<iostream>
#include<fstream>
using namespace std;
int main() {

ifstream fd("duom.txt");
ofstream fr("rez.txt");

fd.close();
fr.close();

return 0;
}

