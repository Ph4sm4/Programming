#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int bin_to_dec(string x)
{
    int sum = 0;
    int p = 0;
    for (int i = x.length() - 1; i >= 0; i--)
    {
        sum += pow(2, p++) * (x[i] - '0');
    }
    return sum;
}

int main()
{

    ifstream plik;
    plik.open("./dane/kopalnia.txt");

    string linia;
    getline(plik, linia);

    string time, weight;

    /*
        wlasciwy - max 5% poprzedniego
        prawdopodobny - 5% < x <= 10%
        bledny - 10% >
    */
    int good = 0;
    int likely = 0;
    int wrong = 0;

    int prevVal = -1;

    while (plik >> time >> weight)
    {
        int kwarta = (int)weight[0] - 64;
        // 0 - 249, 250 - 499, 500 - 749, 750 - 999
        string binWeight = weight.substr(1, weight.length() - 1);
        int actualWeight = (kwarta - 1) * 250 + bin_to_dec(binWeight);

        cout << prevVal << " " << actualWeight << endl;
        if (prevVal == -1)
        {
            good++;
            prevVal = actualWeight;
        }
        else if (abs(prevVal - actualWeight) <= prevVal * 0.05)
        {
            good++;
            prevVal = actualWeight;
        }
        else if (abs(prevVal - actualWeight) > prevVal * 0.05 && abs(prevVal - actualWeight) <= prevVal * 0.1)
        {
            likely++;
            prevVal = actualWeight;
        }
        else if (abs(prevVal - actualWeight) > prevVal * 0.1)
        {
            wrong++;
        }
    }

    cout << good << " " << likely << " " << wrong << endl;

    plik.close();

    ofstream plik2;
    plik2.open("./wyniki/wyniki1.txt");

    plik2 << "1.1." << good << endl;
    plik2 << "1.1." << likely << endl;
    plik2 << "1.1." << wrong << endl;

    plik2.close();

    // 10 minut
    return 0;
}