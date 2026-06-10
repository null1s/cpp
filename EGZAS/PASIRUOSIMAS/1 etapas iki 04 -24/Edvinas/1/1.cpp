#include <iostream>
#include <fstream>
using namespace std;

int main() {
ifstream fd ("d.txt");
ofstream fr("r.txt");
    int a, b;

    fd >> a ;
    fd.ignore();
	fd>> b;

    fr << "Skaicius | Dalijasi ið:" << endl;

    for (int i = a; i <= b; i++) {
        int dalikliuKiekis = 0;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                dalikliuKiekis++;
            }
        }

        fr << i <<"  "<< dalikliuKiekis << endl;
    }

    return 0;
}
