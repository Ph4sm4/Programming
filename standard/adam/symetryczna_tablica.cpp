#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
using namespace std;

int main()
{

    int n;
    cout << "Podaj rozmiar: ";
    cin >> n;

    int **tab = new int *[n];

    for (int i = 0; i < n; i++)
    {
        tab[i] = new int[n];
        int x;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            tab[i][j] = x;
        }
    }

    bool symmetric = true;

    cout << endl;

    for (int i = 0; i <= ceil(n / 2); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tab[i][j] != tab[n - 1 - i][n - 1 - j])
            {
                symmetric = false;
                break;
            }
        }
    }

    cout << boolalpha << symmetric << endl;

    return 0;
}