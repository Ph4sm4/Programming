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
    int podzielne8 = 0;
    int podzielne2 = 0;
    while (getline(plik, linia))
    {
        int x = linia.length() - 1;
        if (linia[x] == '0')
            podzielne2++;
        if (linia[x] == '0' && linia[x - 1] == '0' && linia[x - 2] == '0')
        {
            podzielne8++;
        }
    }
    cout << podzielne2 << " " << podzielne8;

    plik.close();

    return 0;
}