#include <bits/stdc++.h>
using namespace std;

const int n = 10;

int UpBound(int x, int tab[])
{
    int l = 0, p = n - 1, s;
    while (l < p)
    {
        s = (l + p) / 2;
        if (tab[s] >= x)
        {
            p = s;
        }
        else
        {
            l = s + 1;
        }
    }

    return (tab[l] == x ? l : -1);
}

int main()
{
    srand(time(0));

    int tab[n];

    for (int i = 0; i < n; i++)
        tab[i] = rand() % 100;

    for (auto i : tab)
        cout << i << " ";

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tab[i] > tab[j])
            {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
                // swap(tab[i], tab[j]);
            }
        }
    }

    for (auto i : tab)
        cout << i << " ";

    cout << endl;

    int x;
    cin >> x;

    cout << UpBound(x, tab);

    return 0;
}