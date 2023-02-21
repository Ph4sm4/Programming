#include <iostream>
#include <fstream>
#include <string>
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
    int ct = 0;
    while (plik >> x)
    {
        if (sito[x - 1])
            ct++;
    }
    cout << ct;
    plik.close();

    ofstream plik2;
    plik2.open("../wyniki/wyniki3.txt");
    plik2 << ct;
    plik2.close();

    return 0;
}