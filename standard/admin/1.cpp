#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int tab[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> tab[i];
        if (tab[i] % 2 == 0)
        {
            cout << tab[i] * 10 << endl;
        }
        else
        {
            cout << tab[i] << endl;
        }
    }

    return 0;
}