#include <iostream>
using namespace std;

float iloraz(float a, float b)
{
    if (b == 0)
    {
        cout << "nie dzielimy przez ";
        return 0;
    }
    // ...
    return a / b;
}

bool czyRowne(float a, float b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;

    if (czyRowne(a, b) == true)
    {
        cout << "rowne";
    }
    // silnia z 4 -> 1 * 2 * 3 * 4
    // silnia z 10 -> 1 * 2 * 3 * 4 .. * 10
    // silnia z n -> 1 * 2 * 3 * ... * n
    // silnia z 5 -> 1 * 2 * 3 * 4 * 5
    // int wiek;
    // cin >> wiek;
    // switch (wiek)
    // {
    // case 10:
    // {
    //     cout << "dziesieciolatek";
    //     break;
    // }
    // case 20:
    // {
    //     cout << "dwudziestwolatek";
    //     break;
    // }
    // case 30:
    // {
    //     cout << "trzydziestolatek";
    //     break;
    // }
    // case 40:
    // {
    //     cout << 'h';
    //     break;
    // }
    // default:
    // {
    // }
    // }

    return 0;
}