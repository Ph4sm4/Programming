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

    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);

    string x;
    while (plik >> x)
    {
        bool good = true;
        for (int i = 0; i < x.length(); i++)
        {
            for (int j = 0; j < x.length(); j++)
            {
                if (abs(int(x[i]) - int(x[j])) > 10)
                {
                    good = false;
                    break;
                }
            }
            if (!good)
                break;
        }
        if (good)
        {
            plik2 << x << endl;
        }
    }

        plik2.close();

    plik.close();

    return 0;
}