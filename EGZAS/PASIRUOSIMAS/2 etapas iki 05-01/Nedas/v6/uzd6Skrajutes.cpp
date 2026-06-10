#include <fstream>
using namespace std;

void skaiciavimas(int pirm, int antr, int trec, int & val, int & virs, int & nepasiekta)
{
    val = pirm + antr + trec;

    virs = 0;
    nepasiekta = 0;

    if (pirm > 5) virs++;
    else if (pirm < 5) nepasiekta++;

    if (antr > 6) virs++;
    else if (antr < 6) nepasiekta++;

    if (trec > 4) virs++;
    else if (trec < 4) nepasiekta++;
}

void spausdinimas(ofstream & fr, int val, int virs, int nepasiekta)
{
    fr << val << " " << virs << " " << nepasiekta << endl;
}

int main()
{
    ifstream fd("duom6Skrajutes.txt");
    ofstream fr("rez6Skrajutes.txt");

    int savaites, pirm, antr, trec, val, virs, nepasiekta;
    int valandos = 0, viso_virs = 0, viso_nep = 0;
    
    fd >> savaites;
    
    for (int i = 0; i < savaites; i++)
    {
        fd >> pirm >> antr >> trec;

        skaiciavimas(pirm, antr, trec, val, virs, nepasiekta);
        spausdinimas(fr, val, virs, nepasiekta);

        valandos = valandos + val;
        viso_virs = viso_virs + virs;
        viso_nep = viso_nep + nepasiekta;
    }

    fr << valandos << " " << viso_virs << " " << viso_nep << endl; // salygoj atsakymas neteisingas

    fd.close();
    fr.close();
    return 0;
}
