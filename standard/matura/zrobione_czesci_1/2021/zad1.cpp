#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int d = 0;
    int mnoznik = 1;

    while (n)
    {
        d += (9 - n % 10) * mnoznik;
        n /= 10;
        mnoznik *= 10;
    }
    cout << d;

    return 0;
}