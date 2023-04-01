#include <iostream>
#include <string>
using namespace std;

int iloscCyfr(int x);
long long podniesDoPotegi(int a, int b);

int main()
{
    // deklaracja zmiennej:
    // typ_zmiennej nazwa_zmiennej1;
    // typ_zmiennej nazwa_zmiennej2;

    // lub:
    // typ_zmiennej nazwa_zmiennej1, nazwa_zmiennej2;
    int liczba = 5 + 3;
    liczba = liczba + 7;
    liczba = liczba * 3;
    cout << liczba << endl;

    string wynik = "";
    string imie = "auto";

    for (int i = 0; i < 100; i++)
    {
        wynik = wynik + imie;
    }

    cout << wynik << endl;

    // int n;
    // cout << "Podaj n: ";
    // cin >> n;

    // // for (int i = 0; i < n; i++)
    // // {
    // //     cout << i << endl;
    // // }

    // cout << iloscCyfr(12345678) << endl;
    // cout << podniesDoPotegi(2, 10) << endl;

    // string liczba = "45";

    // cout << 5 * 5 << endl; // 25
    // cout << 5 + 5 << endl; // 10
    // cout << 5 - 5 << endl; // 0
    // cout << 5 / 5 << endl; // 1

    return 0;
}

// 1. Napisz program, który dla dowolnej liczby naturalnej, określi ilość cyfr tej liczby.
// 2. Napisz program, który dla dwóch dowolnych liczb naturalnych a i b, podniesie ab.

int iloscCyfr(int x)
{
    int count = 0;
    for (int i = 1; i <= to_string(x).length(); i++)
    {
        count++;
    }
    return count;
}

long long podniesDoPotegi(int a, int b)
{
    long long output = 1;
    for (int i = 0; i < b; i++)
    {
        output *= a;
    }
    return output;
}