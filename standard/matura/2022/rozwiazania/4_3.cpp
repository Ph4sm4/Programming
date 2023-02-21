#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    ifstream plik;
    ofstream plik2;
    ofstream plik3;
    plik2.open("trojki.txt");
    plik3.open("wyniki4.txt", ios::app);
    plik.open("../dane/przyklad.txt");

    int x;
    vector<int> v;
    while (plik >> x)
    {
        v.push_back(x);
    }
    int ileTrojek = 0;
    int ilePiatek = 0;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j < v.size(); j++)
        {
            for (int h = 2; h < v.size(); h++)
            {
                if (v[i] != v[j] && v[j] != v[h] && v[i] != v[h])
                {
                    if (v[h] % v[j] == 0 && v[j] % v[i] == 0)
                    {
                        cout << v[i] << " " << v[j] << " " << v[h] << endl;
                        // plik2 << v[i] << " " << v[j] << " " << v[h] << endl;
                        ileTrojek++;
                    }
                }
                for (int g = 3; g < v.size(); g++)
                {
                    for (int m = 4; m < v.size(); m++)
                    {
                        if (v[i] != v[j] && v[i] != v[h] && v[i] != v[g] && v[i] != v[m] && v[j] != v[h] && v[j] != v[g] && v[j] != v[m] && v[h] != v[g] && v[h] != v[m] && v[g] != v[m])
                        {
                            if (v[m] % v[g] == 0 && v[g] % v[h] == 0 && v[h] % v[j] == 0 && v[j] % v[i] == 0)
                            {
                                ilePiatek++;
                            } // pomyslec nad tym gownem gdyz przy obecnym rozwiazaniu, liczba operacji jaka komputer musi wykonac to 320 bilionow XD
                        }
                    }
                }
            }
        }
    }
    cout << ileTrojek << " " << ilePiatek << endl;

    plik.close();
    plik2.close();
    plik3.close();

    return 0;
}