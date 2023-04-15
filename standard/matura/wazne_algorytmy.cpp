#include <iostream>
using namespace std;

int NWD(int a, int b) // najwiekszy wspolny dzielnik
{
    if (b)
        return NWD(b, a % b);

    return a;
}

int NWW(int a, int b) // najmniejsza wspolna wielokrotnosc
{
    return a / NWD(a, b) * b;
}

void sortuj(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (tab[i] < tab[j])
                swap(tab[i], tab[j]);
        }
    }
}

void wyswietl(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << tab[i] << " ";
    }
}

int main()
{
    int tab[] = {1, 32, 3111, 32, 21, 7};

    wyswietl(tab, *(&tab + 1) - tab);
    sortuj(tab, *(&tab + 1) - tab);
    cout << endl;
    wyswietl(tab, *(&tab + 1) - tab);

    return 0;
}