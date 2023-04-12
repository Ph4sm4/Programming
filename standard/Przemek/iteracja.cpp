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

    int n;
    cin >> n;
    if (n > 1000 && n < 2000)
    {
        cout << "wieksze niz 1000 i mniejsze o 1500" << endl;
    }
    else if (n > 1000 && n < 1500)
    {
        cout << "wieksze niz 1000 i mniejsze o 2000" << endl;
    }
    else if (n < 1000)
    {
        cout << "mniejsza niz 1000" << endl;
    }
    else if (n == 1000)
    {
        cout << "rowna" << endl;
    }

    // napisz program, ktory wczyta od uzytkownika (wraz z komunikatami na ekranie) dwie liczby a i b, a nastepnie
    // podniesie a do potegi b

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

MOZNA PRZYPISYWAC DO JEDNEJ ZMIENNEJ WARTOSCI INNEJ ZMIENNEJ

=========================================================

1. Napisz program, który dla dwóch dowolnych liczb naturalnych a i b, podniesie a do potegi b
2. Napisz program, ktory zliczy sume liczb od 1 do 20
3. Napisz program, ktory dla podanego a i b, zliczy sume liczb od a do b wlacznie
4. Napisz program, ktory wypisze slowo "wieksza" jesli liczba jest wieksza od 1000, "mniejsza" jesli jest mniejsza od 1000 oraz "rowna" jesli jest rowna 1000
5. Reszta z dzielenia i operator modulo
6. Napisz program, ktory dla podanej liczby z klawiatury sprawdzi czy dana liczba jest parzysta i wypisze "tak" jesli jest parzysta i "nie" jesli nie jest
7. Napisz program, ktory dla podanego n, obliczy n!
    przyklad: dla n = 5
    wykona operacje: 1 * 2 * 3 * 4 * 5, a nastepnie wypisze wynik 120


*/

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