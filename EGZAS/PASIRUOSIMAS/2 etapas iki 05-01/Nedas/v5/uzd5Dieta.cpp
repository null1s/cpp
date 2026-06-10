#include <fstream>
using namespace std;

void skaiciavimas(double suvartojo, double & ang, double & bal, double & rie)
{
    ang = suvartojo * (69.3 / 100);
    bal = suvartojo * (12.6 / 100);
    rie = suvartojo * (3.1 / 100);
}

void kalorijos(int suvartojo, int & dienos)
{
    double kcal;
	kcal = suvartojo * (349.0 / 100.0);

    if (kcal >= 1800) dienos++;
}

int main()
{
    ifstream fd("duom5Dieta.txt");
    ofstream fr("rez5Dieta.txt");

    int n, suvartojo, dienos = 0;
    double ang, bal, rie;

    fd >> n >> ang >> bal >> rie;

    for (int i = 0; i < n; i++)
    {
        fd >> suvartojo;

        skaiciavimas(suvartojo, ang, bal, rie);
        kalorijos(suvartojo, dienos);

        fr << ang << " " << bal << " " << rie << endl;
    }

    fr << "Vaida suvartojo reikiama kaloriju kieki " << dienos << " dienas";

	fr.close();
	fd.close();
    return 0;
}
