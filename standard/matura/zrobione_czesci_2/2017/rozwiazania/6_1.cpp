#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main()
{

    ifstream plik;
    ofstream plik2;
    plik.open("../dane/dane.txt");

    int x;
    int maxVal = 0;
    int minVal = INT_MAX;

    while (plik >> x)
    {
        if (x < minVal)
            minVal = x;
        if (x > maxVal)
            maxVal = x;
    }
    cout << minVal << " " << maxVal << endl;

    plik2.open("wyniki6.txt", ios::app);
    plik2 << "6.1" << endl
          << minVal << " " << maxVal << endl;

    plik2.close();
    plik.close();

    return 0;
}