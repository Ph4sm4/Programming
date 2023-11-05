#include <iostream>
using namespace std;

int main()
{

    /*
        i++ oznacza zwiekszenie liczby o 1 -> i = i + 1 lub i += 1
        i++ zawsze zwiekszy ci o 1 i tylko o 1

        stworz zmienne: Hello="Hello" Oraz World="World";
        nastepnie w petli 100 razy:
            wypisz na ekran wynik operacji Hello + " " + World;
    */

    const string PIN = "1234";
    string PIN_wpisywany;
    int proby = 3;

    for (;;)
    {
        if (!proby)
        {
            cout << "*GUNSHOTSSSSS*, naura";
            break;
        }
        cout << "Podaj pin: ";
        cin >> PIN_wpisywany;

        if (PIN_wpisywany == PIN)
        {
            cout << "Welcome in the bank";
            break;
        }
        else // i++, ++i ; i--, --i
        {
            cout << "Niepoprawny PIN, pozostale proby: " << --proby << endl;
        }
    }

    return 0;
}