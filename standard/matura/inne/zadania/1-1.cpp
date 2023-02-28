#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    ifstream plik;
    string linia;
    plik.open("../Dane_2203/szachy_przyklad.txt", ios::in);

    string grid[8];
    int x = 0;

    int emptyColsGridNumber = 0;
    int maxEmptyCols = 0;

    while (getline(plik, linia))
    {
        if (linia == "")
        {
            continue;
        }

        grid[x % 8] = linia;

        if ((x + 1) % 8 == 0)
        {
            int tempEmptyCols = 0;
            bool atLeastOneEmpty = false;
            for (int i = 0; i < 8; i++)
            {
                bool isColEmpty = true;
                for (int j = 0; j < 8; j++)
                {
                    if (grid[j][i] != '.')
                    {
                        isColEmpty = false;
                        break;
                    }
                }
                if (isColEmpty)
                {
                    atLeastOneEmpty = true;
                    tempEmptyCols++;
                }
            }
            if (maxEmptyCols < tempEmptyCols)
                maxEmptyCols = tempEmptyCols;
            if (atLeastOneEmpty)
                emptyColsGridNumber++;
        }

        x++;
    }

    plik.close();

    cout << emptyColsGridNumber << " " << maxEmptyCols;

    return 0;
}