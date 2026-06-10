#include <iostream>
#include <fstream>

using namespace std;

void skaitytiDuom(int& m, string atrinkti[], int minut[], int sec[]);
void rikiuotiZmones(int m, string atrinkti[], int minut[], int sec[]);
void spausdintiRez(int m, string atrinkti[], int minut[], int sec[]);

int main()
{
    int m, minut[30], sec[30];
    string atrinkti[30];

    skaitytiDuom(m, atrinkti, minut, sec);
    rikiuotiZmones(m, atrinkti, minut, sec);
    spausdintiRez(m, atrinkti, minut, sec);

    return 0;
}

void skaitytiDuom(int& m, string atrinkti[], int minut[], int sec[])
{
    ifstream fin("duom.txt");
    int n, val1[30], minut1[30], sec1[30];
    int valandos, minutes, sekundes;
    string prad[30];
    char eil[21];
    fin >> n;
    for(int i = 0; i < n; i++){
        fin.ignore(80, '\n');
        fin.get(eil, 21);
        prad[i] = eil;
        fin >> val1[i];
        fin >> minut1[i];
        fin >> sec1[i];
    }
    fin >> m;
    for(int i = 0; i < m; i++){
        fin.ignore(80, '\n');
        fin.get(eil, 21);
        atrinkti[i] = eil;
        fin >> valandos;
        fin >> minutes;
        fin >> sekundes;
        for(int j = 0; j < n; j++){
            if(prad[j] == atrinkti[i]){
                sec[i] = ((sekundes + (minutes * 60) + (valandos * 3600)) - (sec1[j] + (minut1[j] * 60) + (val1[j] * 3600))) % 60;
                minut[i] = ((sekundes + (minutes * 60) + (valandos * 3600)) - (sec1[j] + (minut1[j] * 60) + (val1[j] * 3600))) / 60;
                break;
            }
        }
    }
    fin.close();
}

void rikiuotiZmones(int m, string atrinkti[], int minut[], int sec[])
{
    for(int i = 0; i < m - 1; i++){
        for(int j = i + 1; j < m; j++){
            if(minut[i] * 60 + sec[i] > minut[j] * 60 + sec[j]){
                string temp = atrinkti[i];
                atrinkti[i] = atrinkti[j];
                atrinkti[j] = temp;
                int temp2 =  minut[i];
                minut[i] = minut[j];
                minut[j] = temp2;
                temp2 = sec[i];
                sec[i] = sec[j];
                sec[j] = temp2;
            }
        }
    }
}

void spausdintiRez(int m, string atrinkti[], int minut[], int sec[])
{
    ofstream fout("rez.txt");
    for(int i = 0; i < m; i++)
        fout << atrinkti[i] << minut[i] << " " << sec[i] << endl;
    fout.close();
}
