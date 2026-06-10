#include <iostream>
#include <fstream>
using namespace std;
int Atbulai(int skaicius) {
    int atbulas = 0;
   
    while (skaicius > 0) {
        int paskutinisSk = skaicius % 10;          
		        atbulas = (atbulas * 10) + paskutinisSk;   
        skaicius = skaicius / 10;                       
    }
   
    return atbulas;
}
int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int n, m;
    fd >> n >> m; 

    int laiminguKiekis = 0;

    
    for (int i = n; i <= m; i++) {
        
        int atbulasSk = Atbulai(i);

       
        if (i == atbulasSk) {
            laiminguKiekis++;
        }
    }

    
    fr << laiminguKiekis << endl;

    fd.close();
    fr.close();

    return 0;
}
