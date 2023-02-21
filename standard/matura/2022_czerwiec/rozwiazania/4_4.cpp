#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{

    ifstream plik;
    plik.open("../dane/liczby.txt");

    int x;
    vector<pair<int, int>> v;

    while (plik >> x)
    {
        bool found = false;
        int index = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == x)
            {
                found = true;
                index = i;
            }
        }
        if (!found)
        {
            pair<int, int> temp;
            temp.first = x;
            temp.second = 1;
            v.push_back(temp);
        }
        else
        {
            v[index].second++;
        }
    }

    int ileRoznych = v.size();
    int ileDwa = 0;
    int ileTrzy = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == 2)
        {
            ileDwa++;
        }
        else if (v[i].second == 3)
        {
            ileTrzy++;
        }
    }
    cout << ileRoznych << " " << ileDwa << " " << ileTrzy << endl;

    plik.close();

    return 0;
}