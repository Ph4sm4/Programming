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
    int minVal = 0;
    int ct = 0;

    vector<vector<int>> v;
    int i = 0;

    while (plik >> x)
    {
        if (ct == 0)
        {
            vector<int> temp;
            v.push_back(temp);
        }
        v.at(i).push_back(x);
        ct++;

        if (ct == 320)
        {
            i++;
            ct = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> p = v.at(i);
        bool good = true;
        int z = p.size() - 1;
        int j = 0;
        while (j < z)
        {
            if (p.at(j) != p.at(z))
            {
                good = false;
                break;
            }
            z--;
            j++;
        }
        if (!good)
            ans++;
    }
    cout << ans;

    plik2.open("wyniki6.txt", ios::app);
    plik2 << "6.2" << endl
          << ans << endl;

    plik2.close();
    plik.close();

    return 0;
}