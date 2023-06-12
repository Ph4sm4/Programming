#include <iostream>
#include <cmath>
using namespace std;

const int N = 100000;
bool czyPierwsze[N];
void sito()
{
    // tutaj ustawiamy wszystkie wartosci na prawda, poczatkowo kazda z liczb jest liczba pierwsza -> a my powoli bedziemy je wykreslac
    // czyli zmieniac w tablicy czyPierwsze z wartosci 1 na 0
    for (int i = 0; i < N; i++)
    {
        czyPierwsze[i] = true;
    }
    // tutaj wywalamy z bomby 1, dlatego ze 1 to nie liczba pierwsza
    czyPierwsze[1] = false;

    // zatem skoro wykreslilismy 1, mozemy zaczac nasza petle od (i = 2)
    // wykonujemy petle poki i < sqrt(N), dlatego ze w naszej drugiej petli
    // ustawiamy j = i * i, i w przypadku gdybysmy nie mieli tego pierwiastka
    // to wychodzimy szybko poza indeks naszej tablicy np:
    /*
        rozmiar tablicy N = 100;
        pierwsze 9 iteracji jest ok, bo j = 9 * 9 -> 81, czyli czyPierwsze[89] nie wywali nam programu
        lecz w przypadku np. 12 iteracji: j = 12 * 12 -> 144, czyli czyPierwsze[144], a przeciez tablica ma tylko 100 indeksow
        zatem wywali nam program bo odwolujemy sie do indeksu ktory nie istnieje


    */
    for (int i = 2; i < sqrt(N); i++)
    {
        // jesli liczba jest pierwsza, to chcemy wywalic wszystkie jej wielokrotnosci
        if (czyPierwsze[i] == true)
        {
            // tutaj ustawiamy j = i * i, czyli na nastepna wielokrotnosc tej liczby
            /*
                np. dla liczby pierwszej 2 otrzymamy: j = 2 * 2 -> 4 i wykreslamy ta 4
                oraz potem wykreslamy wszystkie kolejne liczby zawierajace 2 w sobie (dodajemy po prostu do j -> i)
            */
            for (int j = i * i; j < N; j += i)
            {
                czyPierwsze[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Podaj n: ";
    cin >> n;

    // trzeba pamietac o zainicjowaniu tego sita, bo inaczej nasza tablica czyPierwsze bedzie miala same zera
    sito();
    cout << boolalpha << czyPierwsze[n];

    return 0;
}
