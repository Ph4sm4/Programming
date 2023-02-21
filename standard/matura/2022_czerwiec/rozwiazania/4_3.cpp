#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

const int N = 20000;
bool czyPierwsze[N];

void sito()
{
    for (int i = 0; i < N; i++)
    {
        czyPierwsze[i] = true;
    }
    czyPierwsze[1] = false;

    for (int i = 2; i < sqrt(N); i++)
    {
        if (czyPierwsze[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                czyPierwsze[j] = false;
            }
        }
    }
}

int main()
{

    ifstream plik;
    plik.open("../dane/liczby.txt");

    sito();

    string x;
    while (getline(plik, x))
    {
        string odbicie = "";

        for (int i = x.length() - 1; i >= 0; i--)
        {
            odbicie += x[i];
        }
        int odb = stoi(odbicie);
        int val = stoi(x);

        if (czyPierwsze[val] && czyPierwsze[odb])
        {
            cout << val << endl;
        }
    }

    plik.close();

    return 0;
}