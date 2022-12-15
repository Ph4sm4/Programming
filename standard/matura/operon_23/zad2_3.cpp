#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main()
{

    string genes[] = {"BD", "CA", "CD", "DD", "BC"};

    ifstream plik;
    plik.open("./dane/genetyka.txt");

    string linia;
    int ct = 0;
    while (getline(plik, linia))
    {
        float l = log2(linia.length());
        if (l - int(l) != 0)
        {
            ct++;
            continue;
        }
        for (int i = 0; i < linia.length() - 1; i += 2)
        {
            bool geneFound = false;
            for (int j = 0; j < 5; j++)
            {
                if (linia.substr(i, 2) == genes[j])
                {
                    geneFound = true;
                }
            }
            if (!geneFound)
            {
                ct++;
            }
        }
    }
    cout << ct;
    plik.close();

    return 0;
}