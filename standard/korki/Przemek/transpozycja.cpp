#include <iostream>
#include <ctime>
using namespace std;

const int W = 4, K = 5;
int tab[W][K];
int tab2[K][W];

void wypelnij()
{
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < K; j++)
        {
            tab[i][j] = rand() % 19 - 9;
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

void transp()
{
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < W; j++)
        {
            tab2[i][j] = tab[j][i];
            cout << tab2[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));

    wypelnij();
    cout << endl;
    transp();

    return 0;
}