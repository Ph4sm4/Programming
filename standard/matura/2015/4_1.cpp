#include <bits/stdc++.h>
using namespace std;

int main()
{

    fstream plik;
    plik.open("liczby.txt", ios::in);

    string linia;
    int count = 0;

    while (getline(plik, linia))
    {
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < linia.length(); i++)
        {
            if (linia[i] == '1')
                ones++;
            else
                zeros++;
        }
        if (zeros > ones)
            count++;
    }
    cout << count;

    plik.close();

    return 0;
}