#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

const int N = 2000000;
bool sito[N];

void execSito()
{
    for (int i = 0; i < N; i++)
        sito[i] = true;

    sito[1] = false;
    for (long long i = 2; i < 1000000; i++)
    {
        if (sito[i])
        {
            for (long long j = i * i; j < 1000000; j += i)
            {
                sito[j] = false;
            }
        }
    }
}

int main()
{
    ifstream plik;
    plik.open("../dane/liczby.txt");

    int x;
    execSito();

    int rozkladyMax = 0;
    int rozkladyMin = INT_MAX;
    int liczbaMax = 0;
    int liczbaMin = 0;

    while (plik >> x)
    {
        int rozkladyCurrent = 0;
        for (int i = 2; i <= ceil(x / 2); i++)
        {
            if (sito[i] && sito[x - i])
            {
                rozkladyCurrent++;
            }
        }
        if (rozkladyMax < rozkladyCurrent)
        {
            rozkladyMax = rozkladyCurrent;
            liczbaMax = x;
        }
        if (rozkladyMin > rozkladyCurrent)
        {
            rozkladyMin = rozkladyCurrent;
            liczbaMin = x;
        }
    }

    cout << liczbaMax << " " << rozkladyMax << " " << liczbaMin << " " << rozkladyMin << endl;

    plik.close();

    ofstream plik2;
    plik2.open("../wyniki/wyniki3.txt", ios::app);
    plik2 << liczbaMax << " " << rozkladyMax << " " << liczbaMin << " " << rozkladyMin;
    plik2.close();

    return 0;
}