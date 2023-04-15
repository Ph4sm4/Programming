#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream plik;
    plik.open("../dane/mecz.txt");
    string linia;
    getline(plik, linia);

    int ct = 0;
    for (int i = 0; i < linia.length() - 1; i++)
    {
        if (linia[i] != linia[i + 1])
            ct++;
    }

    cout << ct;

    plik.close();

    ofstream plik2;
    plik2.open("../wyniki/wyniki1.txt");
    plik2 << ct << endl;
    plik2.close();

    return 0;
}