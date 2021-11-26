#include <iostream>
#include <string>
using namespace std;

int main()
{
    int liczba, podstawa, j;
    string x = "";
    cout << "Wprowadz liczbe: ";
    cin >> liczba;
    cout << "Wymien system na ktory zmieniamy te liczbe: ";
    cin >> podstawa;
    while (liczba > 0)
    {
        j = liczba % podstawa;
        if (j < 10)
        {
            x = char('0' + j) + x;
        }
        else
        {
            x = char('A' - 10 + j) + x;
        }
        liczba = liczba / podstawa;
    }
    cout << "Liczba w systemie o podstawie: " << podstawa << " ." << x;
    return 0;
}
