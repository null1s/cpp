#include <fstream>
#include <iomanip>
using namespace std;
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    double A[100];
    int n = 0;
    while (fd >> A[n]) {
        n++;
    }
    fr << fixed << setprecision(1);
    fr << A[0] << endl;
    double skirt, max = 0;
    for (int i = 1; i < n; i++) {
        skirt = A[i] - A[i - 1];
        if (skirt >= 0)
            fr << "(+" << skirt << ")" << endl;
        else
            fr << "(" << skirt << ")" << endl;
        fr << A[i] << endl;
        if (skirt < 0) skirt = -skirt;
        if (skirt > max) max = skirt;
    }
    fr << "----------------" << endl;
    fr << "Dienu skaicius: " << n << endl;
    fr << "Didziausias temperaturos pokytis:" << endl;
    if (max >= 0)
        fr << "+" << max << endl;
    else
        fr << max << endl;
    fd.close();
    fr.close();

    return 0;
}
