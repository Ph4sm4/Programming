#include <bits/stdc++.h>
using namespace std;

const int n = 200;
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

    string kod = "CSK";
    int idNum = 1;
    while (v.size() != n)
    {
        plik.open("ids/id" + to_string(idNum) + ".txt", ios::out);
        while (kod.length() != 6)
        {
            kod += char(chooseRandom());
        }
        if (!count(v.begin(), v.end(), kod))
        {
            v.push_back(kod);
            plik << kod << '\n';
            idNum++;
        }
        kod = "CSK";
        plik.close();
    }

    return 0;
}