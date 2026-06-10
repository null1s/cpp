#include <fstream>

using namespace std;

bool tikrinimas(int simbolis)
{
    // tarpas
    if (simbolis == 32) return true;

    // skyrybos zenklai
    if (simbolis == 33 || simbolis == 44 || simbolis == 46 || simbolis == 63) return true;

    // skaiciai nuo 0 iki 9
    if (simbolis >= 48 && simbolis <= 57) return true;

    // didziosios raides nuo A iki Z
    if (simbolis >= 65 && simbolis <= 90) return true;

    // mazosios raides nuo a iki z
    if (simbolis >= 97 && simbolis <= 122) return true;

    return false;
}

int main()
{
    ifstream fd("Valdonei.txt");
    ofstream fr("Tikrinimo_rezultatai.txt");

    int simbolis;
    bool visi_teisingi = true;

    while (fd >> simbolis)
    {
        if (tikrinimas(simbolis) == false)
        {
            fr << "Neteisingas simbolis" << endl;
            visi_teisingi = false;
        }
    }

    if (visi_teisingi) fr << "Teisingai" << endl;

    fd.close();
    fr.close();
    return 0;
}
