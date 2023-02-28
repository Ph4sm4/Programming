#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int silnia(int x)
{
    if (x == 0)
        return 1;

    int output = 1;
    for (int i = 1; i <= x; i++)
    {
        output *= i;
    }
    return output;
}

int main()
{

    ifstream plik;
    ofstream plik2;
    plik2.open("./wyniki4.txt", ios::app);
    plik.open("../dane/liczby.txt");

    string x;

    while (plik >> x)
    {
        int numValue = stoi(x);
        int digitValue = 0;
        for (int i = 0; i < x.length(); i++)
        {
            digitValue += silnia(x[i] - '0');
        }
        if (digitValue == numValue)
        {
            cout << x << endl;
            plik2 << x << endl;
        }
    }
    plik2.close();
    plik.close();

    return 0;
}