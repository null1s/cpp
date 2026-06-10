#include <iostream>
#include <fstream>
using namespace std;

void skaitymas(int data[], int & n, int nauja_data[], int & m)
{
    ifstream fd("duom9.txt");

    fd >> n;

    for (int i =0 ; i < n ; i++)
    {
        fd >> data[i];
    }

    fd >> m;

    for (int i = 0 ; i < m ; i++)
    {
        fd >> nauja_data[i];
    }

    fd.close();
}

void iterpimas(int data[], int & n, int sk)
{
    int vieta;
	vieta = n;

    for (int i = 0 ; i < n ; i++)
    {
        if (sk < data[i])
        {
            vieta = i;
            break;
        }
    }

    for (int i = n ; i > vieta ; i--)
    {
        data[i] = data[i - 1];
    }

    data[vieta] = sk;
    n++;
}

void isvedimas(int data[], int n)
{
    ofstream fr("rez9.txt");

    for (int i = 0 ; i < n ; i++)
    {
        fr << data[i] << endl;
    }

    fr.close();
}

int main()
{
    int data[100], nauja_data[100];
    int n, m;

    skaitymas(data, n, nauja_data, m);

    for (int i = 0 ; i < m ; i++)
    {
        iterpimas(data, n, nauja_data[i]);
    }

    isvedimas(data, n);

    return 0;
}
