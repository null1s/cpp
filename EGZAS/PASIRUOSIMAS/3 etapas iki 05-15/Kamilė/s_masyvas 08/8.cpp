#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;

void Skaityti(string fv, int A[][4], int &n)
{
    ifstream fd(fv.c_str());

    fd >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            fd >> A[i][j];
        }
    }

    fd.close();
}

int Stipriausias(int A[][4], int eil)
{
    int max = A[eil][0];

    for(int i = 1; i < 4; i++)
    {
        if(A[eil][i] > max)
        {
            max = A[eil][i];
        }
    }

    return max;
}

void Rasyti(string fr, int ang, int pran)
{
    ofstream rez(fr.c_str());

    rez << "Anglija surinko: "
        << ang << endl;

    rez << "Prancuzija surinko: "
        << pran << endl;

    if(ang > pran)
    {
        rez << "Laimejo: Anglija";
    }
    else if(pran > ang)
    {
        rez << "Laimejo: Prancuzija";
    }
    else
    {
        rez << "Lygiosios";
    }

    rez.close();
}

int main()
{
    int A[MAX][4];
    int B[MAX][4];

    int n, m;

    int ang = 0;
    int pran = 0;

    Skaityti("duom1.txt", A, n);
    Skaityti("duom2.txt", B, m);

    for(int i = 0; i < n; i++)
    {
        int a = Stipriausias(A, i);
        int b = Stipriausias(B, i);

        if(a > b)
        {
            ang++;
        }
        else if(b > a)
        {
            pran++;
        }
    }

    Rasyti("rez.txt", ang, pran);

    return 0;
}
