#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream plik;
    plik.open("../dane/mecz.txt");
    string linia;
    getline(plik, linia);

    int winA = 0, winB = 0;
    char whoWon;
    for (int i = 0; i < linia.length(); i++)
    {
        if (winA >= 1000 && winA - winB >= 3)
        {
            whoWon = 'A';
            break;
        }
        else if (winB >= 1000 && winB - winA >= 3)
        {
            whoWon = 'B';
            break;
        }

        if (linia[i] == 'A')
            winA++;
        else
            winB++;
    }

    cout << whoWon << " " << winA << ":" << winB;

    plik.close();

    ofstream plik2;
    plik2.open("../wyniki/wyniki1.txt", ios::app);
    plik2 << whoWon << " " << winA << ":" << winB << endl;
    plik2.close();

    return 0;
}