#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{

    ifstream plik;
    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);
    plik.open("../dane/pary.txt");

    int x;
    string y;
    while (plik >> x >> y)
    {
        int l = 0, p = 1;
        int n = y.length();
        int maxDl = 0;
        char prevCharacter = y[0];
        int start = 0, end = 0;
        while (l < n && p < n)
        {
            if (prevCharacter != y[p])
            {
                l = p;
                prevCharacter = y[p];
                p++;
                continue;
            }
            if (p - l > maxDl)
            {
                maxDl = p - l;
                start = l;
                end = p;
            }
            prevCharacter = y[p];
            p++;
        }
        for (int i = start; i <= end; i++)
        {
            cout << y[i];
            plik2 << y[i];
        }
        cout << " " << maxDl + 1 << endl;
        plik2 << " " << maxDl + 1 << endl;
    }

    plik.close();
    plik2.close();

    return 0;
}
