#include <bits/stdc++.h>
using namespace std;

const int n = 1200;
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

    string kod = "CSZ";
    int idNum = 1;
    int codeCount = 0;
    while (v.size() != n)
    {
        plik.open("ids/id" + to_string(idNum) + ".txt", ios::out | ios::app);
        while (kod.length() != 6)
        {
            kod += char(chooseRandom());
        }
        if (!count(v.begin(), v.end(), kod))
        {
            v.push_back(kod);
            plik << kod << endl;
            codeCount++;
            if (codeCount == 5)
            {
                codeCount = 0;
                idNum++;
            }
        }
        kod = "CSZ";
        plik.close();
    }

    return 0;
}