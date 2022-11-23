#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int convert(string x)
{
    int dec = 0;
    int j = 0;
    for (int i = x.length() - 1; i >= 0; i--)
    {
        dec += (x[i] - '0') * pow(2, j);
        j++;
    }
    return dec;
}

int main()
{

    fstream plik;
    plik.open("liczby.txt", ios::in);

    string linia;
    int count2 = 0;
    int count8 = 0;

    // 0000 0000 0000 0000

    //     1 2 4 8 16 32 64 128

    while (getline(plik, linia))
    {
        string substr;
        if (linia.length() > 8)
            substr = linia.substr(linia.length() - 9, linia.length() - 1);
        else
            substr = linia;

        if (linia[linia.length() - 1] == '0')
            count2++;
        if (convert(substr) % 8 == 0)
            count8++;
    }
    cout << count2 << endl
         << count8;

    plik.close();

    return 0;
}