#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool czyPierwszy[100010];

void sito()
{
    for (int i = 1; i < 100010; i++)
    {
        czyPierwszy[i] = true;
    }
    czyPierwszy[1] = false;

    for (int i = 2; i < sqrt(100010); i++)
    {
        if (czyPierwszy[i])
        {
            for (int j = i * i; j < 100010; j += i)
            {
                czyPierwszy[j] = false;
            }
        }
    }
}

int main()
{

    ifstream plik;
    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);
    plik.open("../dane/liczby.txt");

    int x;
    int liczbaMaxCzynnik = 0;
    int maxCzynnik = 0;

    int liczbaRoznCzynnik = 0;
    int maxRoznCzynnik = 0;

    sito();

    while (plik >> x)
    {
        vector<int> usedDivisors;
        int divider = 2;
        int startingNumber = x;
        int diffDiv = 0;

        while (divider <= x)
        {
            if (x % divider == 0)
            {
                bool found = false;
                for (int i = 0; i < usedDivisors.size(); i++)
                {
                    if (usedDivisors[i] == divider)
                        found = true;
                }
                if (!found)
                    diffDiv++;
                usedDivisors.push_back(divider);
                x /= divider;
            }
            else
            {
                while (true)
                {
                    divider++;
                    if (czyPierwszy[divider])
                        break;
                }
            }
            if (divider == x)
                break;
        }
        if (maxCzynnik < usedDivisors.size())
        {
            maxCzynnik = usedDivisors.size();
            liczbaMaxCzynnik = startingNumber;
        }
        if (maxRoznCzynnik < diffDiv)
        {
            maxRoznCzynnik = diffDiv;
            liczbaRoznCzynnik = startingNumber;
        }
    }
    cout << liczbaMaxCzynnik << " " << maxCzynnik + 1 << " " << liczbaRoznCzynnik << " " << maxRoznCzynnik + 1 << endl;
    plik2 << liczbaMaxCzynnik << " " << maxCzynnik + 1 << " " << liczbaRoznCzynnik << " " << maxRoznCzynnik + 1 << endl;

    plik.close();
    plik2.close();

    return 0;
}