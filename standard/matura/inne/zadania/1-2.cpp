#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{

    ifstream plik;
    string linia;
    plik.open("../Dane_2203/szachy_przyklad.txt", ios::in);

    map<char, int> grid; // K W S H G P
    // wielkie biale, male czarne
    const string letters = "kwshgp";

    int takieSame = 0;
    int minPionki = 99999;

    grid.insert(make_pair('K', 0));
    grid.insert(make_pair('W', 0));
    grid.insert(make_pair('S', 0));
    grid.insert(make_pair('H', 0));
    grid.insert(make_pair('G', 0));
    grid.insert(make_pair('P', 0));
    grid.insert(make_pair('k', 0));
    grid.insert(make_pair('w', 0));
    grid.insert(make_pair('s', 0));
    grid.insert(make_pair('h', 0));
    grid.insert(make_pair('g', 0));
    grid.insert(make_pair('p', 0));

    while (getline(plik, linia))
    {
        if (linia == "")
        {
            grid.clear();
            grid.insert(make_pair('K', 0));
            grid.insert(make_pair('W', 0));
            grid.insert(make_pair('S', 0));
            grid.insert(make_pair('H', 0));
            grid.insert(make_pair('G', 0));
            grid.insert(make_pair('P', 0));
            grid.insert(make_pair('k', 0));
            grid.insert(make_pair('w', 0));
            grid.insert(make_pair('s', 0));
            grid.insert(make_pair('h', 0));
            grid.insert(make_pair('g', 0));
            grid.insert(make_pair('p', 0));
            continue;
        }
        for (int i = 0; i < linia.length(); i++)
        {
            if (linia[i] != '.')
            {
                grid[linia[i]]++;
            }
        }
        bool areEqual = true;
        int allTogether = 0;

        for (int i = 0; i < 6; i++)
        {
            const char small = letters[i];
            const char big = toupper(letters[i]);
            allTogether += grid[small] + grid[big];
            if (grid[small] != grid[big])
            {
                areEqual = false;
            }
        }

        if (areEqual)
        {
            takieSame++;
            if (minPionki > allTogether)
                minPionki = allTogether;
        }
    }

    plik.close();

    cout << takieSame << " " << minPionki;

    return 0;
}