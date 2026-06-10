#include <iostream>
#include <fstream>
#include <iomanip>  
using namespace std;
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    double suma = 0;
    for (int i = 0; i < 6; i++) {
        int n;
        fd >> n;
        double x;
        for (int j = 0; j < n; j++) {
            fd >> x;
            suma += x;
        }
    }
    double kaina;
    fd >> kaina;
    fr << fixed << setprecision(2); 
    fr << suma << endl;
    if (suma >= kaina)
        fr << "Uzteks";
    else
        fr << "Neuzteks";
    return 0;
}
