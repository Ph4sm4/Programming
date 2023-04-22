#include <iostream>
using namespace std;

int main()
{

    int wiek;
    cin >> wiek;
    switch (wiek)
    {
    case 10:
    {
        cout << "dziesieciolatek";
        break;
    }
    case 20:
    {
        cout << "dwudziestwolatek";
        break;
    }
    case 30:
    {
        cout << "trzydziestolatek";
        break;
    }
    }

    return 0;
}