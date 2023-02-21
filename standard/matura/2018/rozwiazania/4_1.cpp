#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int main()
{

    ifstream plik;
    plik.open("../dane/sygnaly.txt");

    int ct = 1;
    string x;
    string output = "";
    while (plik >> x)
    {
        if (ct == 40)
        {
            output += x[9];

            ct = 1;
        }
        else
            ct++;
    }
    cout << output;
    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);
    plik2 << output << endl;

    plik2.close();

    plik.close();

    return 0;
}