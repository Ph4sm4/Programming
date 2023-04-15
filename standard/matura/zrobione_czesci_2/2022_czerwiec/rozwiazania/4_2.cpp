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

    int maxOdb = 0;
    int maxLiczba;
    string x;
    while (getline(plik, x))
    {
        string odbicie = "";

        for (int i = x.length() - 1; i >= 0; i--)
        {
            odbicie += x[i];
        }
        int odb = stoi(odbicie);
        int val = abs(stoi(x) - odb);
        if (maxOdb < val)
        {
            maxOdb = val;
            maxLiczba = stoi(x);
        }
    }
    cout << maxLiczba << " " << maxOdb << endl;

    plik.close();

    return 0;
}