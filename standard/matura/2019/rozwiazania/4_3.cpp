#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int NWD(int a, int b)
{
    if (b != 0)
        return NWD(b, a % b);
    return a;
}

int main()
{

    ifstream plik;
    plik.open("../dane/liczby.txt");

    int l1, l2;
    int start;
    int maxStart;

    int l = 0, p = 1;

    int maxLen = 0;
    int len = 0;
    int maxNwd = 1;

    vector<int> v;
    while (plik >> l2)
    {
        v.push_back(l2);
    }

    l1 = v.at(l);
    l2 = v.at(p);
    int nwd = NWD(l1, l2);
    if (nwd != 1)
        len = 2;

    while (l < v.size() && p < v.size())
    {
        if (nwd == 1)
        {
            l++;
            start = v.at(l);
            len = p - l + 1;
            if (len == 1)
            {
                p++;
                len++;
                if (p == v.size())
                    break;
            }
            nwd = NWD(v.at(l), v.at(l + 1));
            if (len > 2)
            {
                for (int i = l + 2; i <= p; i++)
                {
                    nwd = NWD(nwd, v.at(i));
                }
            }
        }
        else
        {
            if (maxLen < len)
            {
                maxLen = len;
                maxNwd = nwd;
                maxStart = start;
            }
            p++;
            len++;
            nwd = NWD(nwd, v.at(p));
        }
    }

    cout << maxStart << " " << maxLen << " " << maxNwd << endl;

    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);
    plik2 << "4.3" << endl
          << maxStart << " " << maxLen << " " << maxNwd << endl;
    plik2.close();

    plik.close();

    return 0;
}