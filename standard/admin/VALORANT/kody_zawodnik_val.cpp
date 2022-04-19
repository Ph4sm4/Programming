#include <bits/stdc++.h>
using namespace std;

const int n = 1000;
int chooseRandom()
{
    int type = rand() % 3;

    if (!type)
        return rand() % 10 + 48;

    if (type == 1)
        return rand() % 26 + 65;

    return rand() % 26 + 97;
}

int main()
{
    srand(time(NULL));
    vector<string> v;
    // cyfry: 48 - 57
    // duze litery: 65 - 90
    // male litery: 97 - 122 wszystko wlacznie jest
    fstream plik;
    plik.open("kody_zawodnik_val.txt", ios::out);
    string kod = "VAZ";
    while (v.size() != n)
    {
        while (kod.length() != 6)
        {
            kod += char(chooseRandom());
        }
        if (!count(v.begin(), v.end(), kod))
            v.push_back(kod);
        kod = "VAZ";
    }
    copy(v.begin(), v.end(), ostream_iterator<string>(plik, "\n"));
    plik.close();

    return 0;
}