#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int N = 300000;
bool visited[N];
vector<int> tab[N];

void DFS(int x)
{
    visited[x] = true;
    for (int neighbour : tab[x])
    {
        if (!visited[neighbour])
        {
            DFS(neighbour);
        }
    }
}

void resetVis()
{
    for (int i = 0; i < N; i++)
        visited[i] = false;
}

int main()
{
    ifstream plik;
    plik.open("../dane/pary.txt");

    int x, y;
    for (int i = 1; i <= 100000; i++)
    {
        tab[i].push_back(2 * i);
        tab[i].push_back(2 * i + 1);
    }
    ofstream plik2;
    plik2.open("../wyniki/wyniki2.txt");

    while (plik >> x >> y)
    {
        DFS(x);
        if (visited[y])
        {
            plik2 << x << " " << y << endl;
        }
        resetVis();
    }

    plik.close();
    plik2.close();

    return 0;
}