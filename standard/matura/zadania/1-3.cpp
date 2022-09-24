#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

struct point
{
    int x, y;
};

int main()
{

    ifstream plik;
    string linia;
    plik.open("../Dane_2203/szachy_przyklad.txt", ios::in);

    int czarnySzachuje = 0;
    int bialySzachuje = 0;

    // w W

    string grid[8];
    int x = 0;

    while (getline(plik, linia))
    {
        if (linia == "")
        {

            continue;
        }

        grid[x % 8] = linia;

        if ((x + 1) % 8 == 0)
        {
            // biale szachuje czarne
            bool bialySzachRow = true;
            bool bialySzachCol = true;
            for (int i = 0; i < 8; i++)
            {
                bool pionekFoundRow = false;
                bool pionekFoundRow2 = false;
                bool pionekFoundCol = false;
                bool pionekFoundCol2 = false;
                for (int j = 0; j < 8; j++)
                {
                    if ((grid[i][j] == 'k' || grid[i][j] == 'W') && !pionekFoundRow)
                    {
                        pionekFoundRow = true;
                    }
                    else if (pionekFoundRow && (grid[i][j] != '.' && grid[i][j] != 'k' && grid[i][j] != 'W') || (j == 7 && (!pionekFoundRow || !pionekFoundRow2)))
                    {
                        bialySzachRow = false;
                    }
                    else if ((grid[i][j] == 'k' || grid[i][j] == 'W') && pionekFoundRow)
                    {
                        pionekFoundRow2 = true;
                    }

                    if ((grid[j][i] == 'k' || grid[j][i] == 'W') && !pionekFoundCol)
                    {
                        pionekFoundCol = true;
                    }
                    else if (pionekFoundCol && (grid[j][i] != '.' && grid[j][i] != 'k' && grid[j][i] != 'W') || (j == 7 && (!pionekFoundCol || !pionekFoundCol2)))
                    {
                        bialySzachCol = false;
                    }
                    else if ((grid[j][i] == 'k' || grid[j][i] == 'W') && pionekFoundCol)
                    {
                        pionekFoundCol2 = true;
                    }
                }
                if (bialySzachRow || bialySzachCol)
                {
                    bialySzachuje++;
                }
            }
            // czarny szachuje czarne
            bool czarnySzachRow = true;
            bool czarnySzachCol = true;
            for (int i = 0; i < 8; i++)
            {
                bool pionekFoundRow = false;
                bool pionekFoundRow2 = false;
                bool pionekFoundCol = false;
                bool pionekFoundCol2 = false;
                for (int j = 0; j < 8; j++)
                {
                    if ((grid[i][j] == 'K' || grid[i][j] == 'w') && !pionekFoundRow)
                    {
                        pionekFoundRow = true;
                    }
                    else if (pionekFoundRow && (grid[i][j] != '.' && grid[i][j] != 'K' && grid[i][j] != 'w') || (j == 7 && (!pionekFoundRow || !pionekFoundRow2)))
                    {
                        czarnySzachRow = false;
                    }
                    else if ((grid[i][j] == 'K' || grid[i][j] == 'w') && pionekFoundRow)
                    {
                        pionekFoundRow2 = true;
                    }

                    if ((grid[j][i] == 'K' || grid[j][i] == 'w') && !pionekFoundCol)
                    {
                        pionekFoundCol = true;
                    }
                    else if (pionekFoundCol && (grid[j][i] != '.' && grid[j][i] != 'K' && grid[j][i] != 'w') || (j == 7 && (!pionekFoundCol || !pionekFoundCol2)))
                    {
                        czarnySzachCol = false;
                    }
                    else if ((grid[j][i] == 'K' || grid[j][i] == 'w') && pionekFoundCol)
                    {
                        pionekFoundCol2 = true;
                    }
                }
                if (czarnySzachRow || czarnySzachCol)
                {
                    czarnySzachuje++;
                }
            }
        }

        x++;
    }

    plik.close();

    cout << bialySzachuje << " " << czarnySzachuje;

    return 0;
}