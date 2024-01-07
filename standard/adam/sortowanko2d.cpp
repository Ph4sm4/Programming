#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void print2D(int **tab, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));

    int n, m;
    cout << "Enter dimensions (n x m): ";
    cin >> n >> m;

    int **tab = new int *[n];
    int *sorted = new int[n * m];

    for (int i = 0; i < n; i++)
    {
        tab[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            int x = rand() % 100;
            tab[i][j] = x;
            sorted[n * j + i] = x;
            cout << x << " ";
        }
        cout << endl;
    }
    // cout << endl;
    // for (int i = 0; i < n * m; i++)
    //     cout << sorted[i] << " ";

    cout << endl
         << endl;

    for (int i = 0; i < n * m; i++)
    {
        int ind = i;
        for (int j = i + 1; j < n * m; j++)
        {
            if (sorted[ind] > sorted[j])
            {
                ind = j;
            }
        }
        if (ind != i)
            swap(sorted[ind], sorted[i]);
    }

    // for (int i = 0; i < n * m; i++)
    //     cout << sorted[i] << " ";

    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tab[i][j] = sorted[n * j + i];
        }
    }

    print2D(tab, n, m);

    return 0;
}