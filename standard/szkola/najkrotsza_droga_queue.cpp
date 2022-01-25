#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;

struct pole
{
    int w, k;
};

const int N = 20;

void WczytajLabirynt(int Lab[][N])
{
    string s;
    ifstream we("labirynt.txt");

    for (int i = 0; i < N; i++)
    {
        we >> s;
        for (int j = 0; j < N; j++)
        {
            if (s[j] == 'X')
                Lab[i][j] = -1;
            else
                Lab[i][j] = 0;
        }
    }

    we.close();
}

void WypiszLabirynt(int Lab[][N])
{
    cout << "   ";

    for (int j = 0; j < N; j++)
        cout << setw(3) << j;

    cout << endl;

    for (int i = 0; i < N; i++)
    {
        cout << setw(3) << i;
        for (int j = 0; j < N; j++)
        {
            if (Lab[i][j] == -1)
                cout << "  X";
            else if (Lab[i][j] == -2)
                cout << "  D";
            else
                cout << "   ";
        }
        cout << endl;
    }
}

bool Droga(int Lab[][N], pole p1, pole &p2)
{
    int w, k;
    bool wyjscie = false;
    queue<pole> Q;
    Q.push(p1);
    Lab[p1.w][p1.k] = 1;

    while (!wyjscie && !Q.empty())
    {
        p2 = Q.front();
        Q.pop();
        w = p2.w;
        k = p2.k;

        if (w == 0 || w == N - 1 || k == 0 || k == N - 1)
            wyjscie = true;
        else
        {
            if (Lab[w - 1][k] == 0)
            {
                Lab[w - 1][k] = Lab[w][k] + 1;
                p2.w = w - 1;
                p2.k = k;
                Q.push(p2);
            }

            if (Lab[w + 1][k] == 0)
            {
                Lab[w + 1][k] = Lab[w][k] + 1;
                p2.w = w + 1;
                p2.k = k;
                Q.push(p2);
            }

            if (Lab[w][k - 1] == 0)
            {
                Lab[w][k - 1] = Lab[w][k] + 1;
                p2.w = w;
                p2.k = k - 1;
                Q.push(p2);
            }

            if (Lab[w][k + 1] == 0)
            {
                Lab[w][k + 1] = Lab[w][k] + 1;
                p2.w = w;
                p2.k = k + 1;
                Q.push(p2);
            }
        }
    }

    return wyjscie;
}

void OznaczDroge(int Lab[][N], int w, int k)
{
    int x = Lab[w][k];
    Lab[w][k] = -2;

    while (x > 1)
    {
        x--;
        if (w > 0 && Lab[w - 1][k] == x)
            w--;
        else if (w < N - 1 && Lab[w + 1][k] == x)
            w++;
        else if (k > 0 && Lab[w][k - 1] == x)
            k--;
        else
            k++;

        Lab[w][k] = -2;
    }
}

int main()
{
    int Lab[N][N];
    pole p1, p2;

    WczytajLabirynt(Lab);
    WypiszLabirynt(Lab);

    cout << "Pole startowe (nr wiersza): ";
    cin >> p1.w;
    cout << "Pole startowe (nr kolumny): ";
    cin >> p1.k;

    if (Droga(Lab, p1, p2))
    {
        OznaczDroge(Lab, p2.w, p2.k);
        WypiszLabirynt(Lab);
    }
    else
        cout << "Brak drogi";

    return 0;
}