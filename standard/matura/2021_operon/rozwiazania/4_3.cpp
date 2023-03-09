#include <iostream>
#include <fstream>
#include <cmath>
#include <utility>
using namespace std;

int main()
{

    ifstream plik;
    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);
    plik.open("../dane/pary.txt");

    int x;
    string y;
    pair<int, string> smallest = {0, ""};
    while (plik >> x >> y)
    {
        if (x == y.length())
        {
            if (-x < smallest.first || -x == smallest.first && y < smallest.second)
            {
                smallest = {x, y};
            }
        }
    }
    cout << smallest.first << " " << smallest.second;
    plik2 << "6.3:" << endl
          << smallest.first << " " << smallest.second;

    plik.close();
    plik2.close();

    return 0;
}
