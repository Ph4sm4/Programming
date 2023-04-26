#include <iostream>
using namespace std;

int iloraz(int a, int b)
{
    if (b == 0)
    {
        cout << "nie dzielimy przez ";
        return 0;
    }
    // ...
    return a / b;
}

int main()
{
    cout << iloraz(10, 0);
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