#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct asmuo {
    string vardas;
    double skaicius;
    int data;
    string salis;
};

int main() {
    asmuo A[10]; // Skaièius galima padaryti dinamiðkà, bet èia pavyzdþiui 10
    int sk;

    ifstream fd("duom.csv"); // Atidarome CSV failà
    ofstream fr("rez.txt"); // Iðvesties failas

    sk = 0;
    string line;
    while (getline(fd, line)) { 
    sk++;
    }

    // Uþsidarome failà ir vël atidarome já skaitymui
    fd.clear();  // Atstatome klaidø bûsenà
    fd.seekg(0); // Gráþtame á failo pradþià

    // Nuskaitome duomenis ið failo
    for (int i = 0; i < sk; i++) {
        getline(fd, line); // Nuskaityti eilutæ

        stringstream ss(line);
        getline(ss, A[i].vardas, ';'); // Nuskaityti vardà
        ss >> A[i].skaicius; // Nuskaityti skaièiø
        ss.ignore(); // Ignoruoti ';'
        ss>>A[i].data;// Nuskaityti datà
        ss.ignore(); // Ignoruoti ';'
        getline(ss, A[i].salis); // Nuskaityti ðalá
    }

    // Iðvedame duomenis á ekranà ir failà
    for (int i = 0; i < sk; i++) {
        cout << A[i].vardas << " " << A[i].skaicius << " " << A[i].data << " " << A[i].salis << endl;
        fr << A[i].vardas << " " << A[i].skaicius << " " << A[i].data << " " << A[i].salis << endl;
    }

    fd.close();
    fr.close();

    return 0;
}

