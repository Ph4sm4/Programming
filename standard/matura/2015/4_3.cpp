#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() // MIN OK, MAX NOT WORKING
{

    fstream plik;
    plik.open("liczby.txt", ios::in);

    string linia;
    int ct = 1;

    pair<int, string> max; // line number, line
    pair<int, pair<int, string>> min;

    // 1011110 -> 1 + 2 + 4 + 16 = 23
    // 0110000 -> 16 + 8 = 24

    bool first = true;

    while (getline(plik, linia))
    {
        if (first)
        {
            max.first = 1;
            max.second = linia;
        }
        if (first)
        {
            min.first = linia.length();
            min.second.first = 1;
            min.second.second = linia;
            first = false;
        }

        if (max.second.length() < linia.length())
        {
            max.second = linia;
            max.first = ct;
        }
        else if (max.second.length() == linia.length())
        {
            for (int i = 1; i < max.second.length(); i++)
            {
                if (max.second[i] - '0' < linia[i] - '0')
                {
                    max.second = linia;
                    max.first = ct;

                    break;
                }
                else if (max.second[i] - '0' != linia[i] - '0')
                {
                    break;
                }
            }
        }

        for (int i = 1; i < min.second.second.length(); i++)
        {
            if (i < linia.length())
            {
                if (min.second.second[i] - '0' > linia[i] - '0')
                {
                    min.second.second = linia;
                    min.second.first = ct;
                    break;
                }
            }
        }

        ct++;
    }

    cout << min.second.first << endl
         << max.first;

    plik.close();

    return 0;
}
