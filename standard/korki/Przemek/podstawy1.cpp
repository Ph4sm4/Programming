#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string imie, nazwisko;
    // cout << "Podaj imie: ";
    // cin >> imie;
    // cout << "Podaj nazwisko: ";
    // cin >> nazwisko;

    // cout << "Twoje imie i nazwisko: " << imie << " " << nazwisko << endl;

    // imie = "Oasdlaf";

    // if (imie == "Olaf")
    // {
    //     cout << "Czesc";
    // }
    // else
    // {
    //     cout << "Dowidzenia";
    // }
    int n;
    cout << "Podaj n: ";
    cin >> n;
    for (int i = 0; i < n; i += 2)
    {
        cout << i << " ";
    }

    /*
        int - calkowita
        string - wyraz, literal znakowy
        char - znak, C, D, A, b, 4
        float - 5,15 10,23
        bool - prawda/falsz
    */

    return 0;
}