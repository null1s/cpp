#include <fstream>
using namespace std;

void skaiciavimas(int si, int vi, int & val, int & min)
{
    int laikas = (si * 60) / vi;

    min = min + laikas;

    val = val + min / 60;
    min = min % 60;

    val = val % 24;
}

int main()
{
    ifstream fd("duom2Kelione.txt");
    ofstream fr("rez2Kelione.txt");

    int val, min, n;
  
    fd >> val >> min >> n;

    for (int i = 0; i < n; i++)
    {
        int si, vi;
        fd >> si >> vi;

        skaiciavimas(si, vi, val, min);

        fr << i+1 << " " << val << " " << min << endl;
    }

	fr.close();
	fd.close();
    return 0;
}
