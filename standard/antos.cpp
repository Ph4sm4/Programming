#include <bits/stdc++.h>
using namespace std;

const int n = 10;

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

    return 0;
}