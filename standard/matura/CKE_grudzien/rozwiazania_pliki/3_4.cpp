#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N = 2000000;
bool sito[N];

string convertHex(int x)
{
    string output = "";
    string letters = "ABCDEF";
    while (x)
    {
        int reminder = x % 16;
        if (reminder > 9)
            output += letters[reminder - 10];
        else
            output += to_string(reminder);

        x /= 16;
    }
    string reversedOutput;
    for (int i = output.length() - 1; i >= 0; i--)
        reversedOutput += output[i];
    return reversedOutput;
}
int tab[16];

int main()
{
    ifstream plik;
    plik.open("../dane/liczby.txt");

    int x;
    string allTogether = "";
    while (plik >> x)
    {
        allTogether += convertHex(x);
    }
    string letters = "ABCDEF";
    for (int i = 0; i < allTogether.length(); i++)
    {
        int z = allTogether[i] - '0';
        int c = int(allTogether[i]);
        if (z < 10)
        {
            tab[z]++;
        }
        else
        {
            tab[c - 55]++;
        }
    }

    plik.close();

    ofstream plik2;
    plik2.open("../wyniki/wyniki3.txt", ios::app);

    for (int i = 0; i < 16; i++)
    {
        if (i < 10)
        {
            plik2 << i << " " << tab[i] << endl;
        }
        else
        {
            plik2 << char(i + 55) << " " << tab[i] << endl;
        }
    }
    plik2.close();

    return 0;
}