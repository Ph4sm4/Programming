#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main()
{

    ifstream plik;
    plik.open("../dane/liczby.txt");

    string linia;
    int ct = 0;
    while (getline(plik, linia))
    {
        int zera = 0;
        int jedynki = 0;

        for (int i = 0; i < linia.length(); i++)
        {
            if (linia[i] == '0')
                zera++;
            else
                jedynki++;
        }
        if (zera > jedynki)
            ct++;
    }
    cout << ct;

    plik.close();

    return 0;
}