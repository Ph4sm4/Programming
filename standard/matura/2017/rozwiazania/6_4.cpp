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
        vector<int> temp;
        for (int j = 0; j < v.size(); j++)
        {
            temp.push_back(v.at(j).at(i));
        }
        int l = 0, p = 1;
        int len = 1, maxLen = 1;
        for (int j = 0; j < temp.size() - 1; j++)
        {
            if (temp[j] == temp[j + 1])
                len++;
            else
            {
                len = 1;
            }
            if (maxLen < len)
                maxLen = len;
        }

        if (ans < maxLen)
            ans = maxLen;
    }
    cout << ans;

    plik2.open("wyniki6.txt", ios::app);
    plik2 << "6.4" << endl
          << ans << endl;

    plik2.close();
    plik.close();

    return 0;
}