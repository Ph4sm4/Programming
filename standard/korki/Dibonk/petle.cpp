#include <iostream>
using namespace std;

int main()
{

    /*


        * na nastepnej lekcji zrobic juz tablice
            ! zadanka 1d:
                - Napisz program wczytujący z klawiatury 10 liczb całkowitych. Wczytane liczby należy wydrukować na ekranie.
                - Napisz program wczytujący z klawiatury n liczb całkowitych. Program ma znaleźć największą spośród
podanych liczb i wydrukować ją na ekranie.
                - Napisz program wczytujący ciąg liczb całkowitych. Wydrukuj na ekranie kolejno wszystkie parzyste
spośród podanych liczb.
                - Napisz program wczytujący ciąg liczb rzeczywistych. Każdą podana liczbę należy podnieść do kwadratu, a
następnie wydrukować na ekranie.
                - Napisz program wczytujący z klawiatury n liczb całkowitych. Program ma znaleźć największą spośród
podanych liczb oraz wydrukować na ekranie informację mówiącą o tym, ile razy największa liczba wystąpiła w
podanym ciągu liczb.

        * potem zrobic vectory i inne kontenery
        * nastepnie korzystanie fstream
        * potem dopiero funkcje

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