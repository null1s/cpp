#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
double Kaina(int zmoniuSk, double x, double y, double z) {
    if (zmoniuSk < 10) {
        return zmoniuSk * x;
    } else if (zmoniuSk >= 10 && zmoniuSk <= 19) {
        return zmoniuSk * y;
    } else { 
        return zmoniuSk * z;
    }
}

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int n, a, b;
    double x, y, z;

    fd >> n >> a >> b;
    fd >> x >> y >> z;

    fr << fixed << setprecision(2);


    double bendgrKaina = Kaina(n, x, y, z);
    double mokKaina = Kaina(a, x, y, z);
    double mokyKaina = Kaina(b, x, y, z);
   
    fr << bendgrKaina << " " << mokKaina << " " << mokyKaina  << "\n";

    int bendrasSuAukletiniais = n + 4;
    double kainaSuAukletiniais = Kaina(bendrasSuAukletiniais, x, y, z);
   
    fr << kainaSuAukletiniais << "\n";

    double kainaVienamNariui = kainaSuAukletiniais / n;
   
    fr << kainaVienamNariui << "\n";

    fd.close();
    fr.close();

    return 0;
}
