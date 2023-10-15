#include <iostream>
#include <string>
using namespace std;

int main()
{
    string wyraz = "Pogchamp 5";
    int liczba_calkowita = 22500;
    float liczba_przecinkowa = 22.5;

    bool zmiennaPrawdaFalsz = false;
    /*
        zmienna bool (boolean) przechowuje wartosci prawda/falsz (1/0)
        kazda zmienna liczbowa rozna od 0 bedzie traktowana jako prawdziwa oraz kazdy wyraz o dlugosci > 0 bedzie prawdziwy
    */
    char znak = 'd'; // pojedynczy znak z klawiatury

    /*
        cin - pobiera ci wartosc od usera (czyli z terminalu) az do napotkania znaku bialego (spacja lub enter)
        w przypadku gdy chcemy zapisac jakas wartosc wyrazowa, ktora ma np. spacje uzywamy funkcji
        getline(). jest zawarta w bibliotece string -> #include <string> na poczatku pliku

        przyklad:
        getline(cin, wyraz); gdzie cin to operator strumienia, a wyraz to nasza zmienna typu string :)

    */
    cout << "Podaj ulubione miasto i kraj: ";
    string kraj, miasto;
    cin >> miasto >> kraj;

    if (kraj == "Polska" && miasto == "Warszawa")
    {
        // operator && (AND) pozwala na laczenie warunkow -> if wykona sie tylko wtedy gdy oba warunki sa prawdziwe
        cout << "stolica polski";
    }
    else if (kraj == "USA" || kraj == "UK")
    {
        /* operator || (OR) sprawia, ze if wykona sie wtedy gdy chociaz jeden z warunkow jest prawdziwy
        oczywiscie zarowno && jak i || mozemy laczyc w nieskonczonosc
        np:
        if((kraj == "Polska"|| kraj == "Niemcy") && (miasto == "Warszawa" || miasto == "Berlin")) {
            cout << "Jest to stolica Polski lub niemiec";
        }
        */
        cout << "inglisz spiking pipul";
    }
    else
    {
        cout << "jakies gowno";
    }

    return 0;
}