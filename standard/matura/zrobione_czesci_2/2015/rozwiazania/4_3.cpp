#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main()
{

    ifstream plik;
    plik.open("../dane/liczby.txt");

    string linia;
    pair<int, string> minimal{INT_MAX, ""};
    pair<int, string> maximum{0, ""};

    int lineNumMin = 1;
    int lineNumMax = 1;
    int currLineNum = 1;

    while (getline(plik, linia))
    {
        int len = linia.length();
        if (minimal.first > len)
        {
            minimal.first = len;
            minimal.second = linia;
            lineNumMin = currLineNum;
        }
        else if (minimal.first == len)
        {
            bool greater = false;
            for (int i = 0; i < len; i++)
            {
                if (minimal.second[i] - '0' < linia[i] - '0')
                {
                    greater = true;
                    break;
                }
                else if (minimal.second[i] - '0' > linia[i] - '0')
                {
                    break;
                }
            }
            if (!greater)
            {
                minimal.first = len;
                minimal.second = linia;
                lineNumMin = currLineNum;
            }
        }
        if (maximum.first < len)
        {
            maximum.first = len;
            maximum.second = linia;
            lineNumMax = currLineNum;
        }
        else if (maximum.first == len)
        {
            bool smaller = false;
            for (int i = 0; i < len; i++)
            {
                if (maximum.second[i] - '0' > linia[i] - '0')
                {
                    smaller = true;
                    break;
                }
                else if (maximum.second[i] - '0' < linia[i] - '0')
                {
                    break;
                }
            }
            if (!smaller)
            {
                maximum.first = len;
                maximum.second = linia;
                lineNumMax = currLineNum;
            }
        }

        currLineNum++;
    }
    cout << lineNumMin << " " << lineNumMax << endl;

    plik.close();

    return 0;
}
// 10001001011101010 <- obecnie max
// 10101101001100110