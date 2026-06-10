#include <iostream>
#include <fstream>

using namespace std;

int atbulas(int sk)
{
    int atv = 0;

    while (sk > 0)
    {
        atv = atv * 10 + sk % 10;
        sk /= 10;
    }

    return atv;
}

int main() 
{
    ifstream fd("duom2.txt");
    ofstream fr("rez2.txt");

    int n, m, suma = 0;
    fd >> n >> m;

    for (int i = n; i <= m; i++)
    {
        if (i == atbulas(i))
        {
            suma++;
        }
    }

    fr << suma;

    fd.close();
    fr.close();
    return 0;
}
