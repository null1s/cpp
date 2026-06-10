#include <iostream>
#include <fstream>
#include <cmath>    
#include <iomanip>  

using namespace std;

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");


    double dabar_temp;
    double ankst_temp;

    fd >> ankst_temp;
        fr << fixed << setprecision(1) << ankst_temp << endl;
   
   

    int dienuSk = 1;      
    double maxPokytisAbs = -1;  
    double tikrasisMaxPokytis = 0;

    while (fd >> dabar_temp) {
        dienuSk++;


        double pokytis = dabar_temp - ankst_temp;

        fr << fixed << setprecision(1) << dabar_temp << " (";
        if (pokytis >= 0) {
            fr << "+";
        }
        fr << pokytis << ")" << endl;

       
        if (abs(pokytis) > maxPokytisAbs) {
            maxPokytisAbs = abs(pokytis);
            tikrasisMaxPokytis = pokytis;
        }

       
        ankst_temp = dabar_temp;
    }

   
    fr << "-----------------------" << endl;
    fr << "Dienu skaicius: " << dienuSk << endl;
    fr << "Didþiausias temperaturos pokytis: ";
    if (tikrasisMaxPokytis >= 0) {
        fr << "+";
    }
    fr << fixed << setprecision(1) << tikrasisMaxPokytis << endl;

    fd.close();
    fr.close();

    return 0;
}
