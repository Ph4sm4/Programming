#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    ifstream plik;
    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);
    plik.open("../dane/liczby.txt");

    string linia;
    int ct = 0;
    string first = "";

    while (plik >> linia)
    {
        if (linia[0] == linia[linia.length() - 1])
        {
            ct++;
            if (!first.length())
                first = linia;
        }
    }
    cout << ct << " " << first << endl;
    plik2 << ct << " " << first << endl;

    plik.close();
    plik2.close();

    return 0;
}