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

    /* wytlumacz jaka jest roznica miedzy zapisem:
    string imie = "Olaf";
    cout << imie;

    a

    string imie = "Olaf";
    cout << "imie";

    =========================================================

    ktory kod zadziala, a ktory nie :
string imie = "Olaf";
    1. cout << imie + "Dalach";

    2.
    string imie = "Olaf";
    string nazwisko = "Dalach";
    cout << imie + nazwisko;

    =========================================================

    co zostanie wypisane?
    int liczba = 5.5;
    cout << liczba;

    float liczba2 = 2.123;
    cout << liczba2;

    =========================================================

    co zostanie wypisane?
    int liczba1 = 3;
    int liczba2 = 4;
    cout << liczba1 / liczba2;

    int liczba3 = 4;
    float liczba4 = 5;
    cout << liczba3 / liczba4;


    =========================================================

    1. napisz petle, ktora do liczby 10 doda liczbe podana przez uzytkownika 7 razy
    2. napisz petle, ktora do slowa "drzewo" dopisze "kasztanowe" 3 razy (wynik ma byc: drzewokasztanowekasztanowekasztanowe)
    3. napisz petle, ktora sprawdzi w jaki sposob liczba 4 dzieli sie przez liczby 1,2,...,10 (zalezy nam na DOKLADNYM wyniku - z przecinkiem)
    4. napisz petle, ktora przemnozy przez siebie liczbe 2, dziesiec razy
    */

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
// 2. Napisz program, który dla dwóch dowolnych liczb naturalnych a i b, podniesie a do potegi b.

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