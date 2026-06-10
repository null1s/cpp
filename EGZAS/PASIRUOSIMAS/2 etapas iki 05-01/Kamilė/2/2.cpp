#include <iostream>
#include <fstream>
using namespace std;
int apversti(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}
int main() {
    ifstream fd("duom.txt");
    ofstream fr("rez.txt");
    int n, m;
    fd >> n >> m;
    int kiek = 0;
    for (int i = n; i <= m; i++) {
        if (i == apversti(i)) {
            kiek++;
        }
    }
    fr << kiek;
    fd.close();
    fr.close();
    return 0;
}
