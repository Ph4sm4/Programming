#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{

    ifstream plik;
    plik.open("../dane/liczby.txt");

    string x;
    while (getline(plik, x))
    {
        string odbicie = "";

        for (int i = x.length() - 1; i >= 0; i--)
        {
            odbicie += x[i];
        }
        if (stoi(odbicie) % 17 == 0)
        {
            cout << odbicie << endl;
        }
    }

    plik.close();

    return 0;
}