#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{

    ifstream plik;
    plik.open("../dane/liczby.txt");

    int x;
    int ct = 0;

    vector<int> v;
    for (int i = 0; pow(3, i) <= 100000; i++)
    {
        v.push_back(pow(3, i));
    }

    while (plik >> x)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (x == v[i])
                ct++;
        }
    }
    cout << ct;

    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);
    plik2 << ct << endl;
    plik2.close();

    plik.close();

    return 0;
}