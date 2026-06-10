#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fd("d.txt");
    ofstream fr("r.txt");

    int n;
    fd >> n;

    int id[100];
    int balai[100];

    for (int i = 0; i < n; i++) {
        fd >> id[i] >> balai[i];
    }

    fr << "Pirmasis: ";
    for (int i = 0; i < n; i++) {
        if (balai[i] >= 1 && balai[i] <= 3) {
            fr << id[i] << " ";
        }
    }
    fr << endl;

    fr << "Antrasis: ";
    for (int i = 0; i < n; i++) {
        if (balai[i] >= 4 && balai[i] <= 6) {
            fr << id[i] << " ";
        }
    }
    fr << endl;

    fr << "Treciasis: ";
    for (int i = 0; i < n; i++) {
        if (balai[i] >= 7 && balai[i] <= 10) {
            fr << id[i] << " ";
        }
    }
    fr << endl;

    fd.close();
    fr.close();

    return 0;
}
