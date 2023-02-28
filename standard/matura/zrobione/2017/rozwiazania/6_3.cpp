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
        for (int j = 0; j < v.at(i).size(); j++)
        {
            int s = v.at(i).size();
            if (j + 1 < s && abs(v[i][j] - v[i][j + 1]) > 128)
                ans++;
            else if (j - 1 >= 0 && abs(v[i][j] - v[i][j - 1]) > 128)
                ans++;
            else if (i + 1 < v.size() && abs(v[i][j] - v[i + 1][j]) > 128)
                ans++;
            else if (i - 1 >= 0 && abs(v[i][j] - v[i - 1][j]) > 128)
                ans++;
        }
    }
    cout << ans;

    plik2.open("wyniki6.txt", ios::app);
    plik2 << "6.3" << endl
          << ans << endl;

    plik2.close();
    plik.close();

    return 0;
}