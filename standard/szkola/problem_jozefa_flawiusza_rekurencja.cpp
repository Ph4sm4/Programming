#include <bits/stdc++.h>
using namespace std;
int flawiusz(int);

int main()
{
    int n;
    cout << "Podaj ile mamy elementow: ";
    cin >> n;
    cout << flawiusz(n);
    return 0;
}

int flawiusz(int n)
{
    if (!n)
        return 0;

    if (!(n % 2))
        return 2 * flawiusz(n / 2) - 1;

    return 2 * flawiusz(n / 2) + 1;
}
