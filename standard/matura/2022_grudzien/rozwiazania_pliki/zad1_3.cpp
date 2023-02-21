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

    int passy = 0;
    int currentStreak = 1;
    char currentStreakTeam = linia[0];

    int maxLen = 0;
    char maxLenTeam;

    for (int i = 1; i < linia.length(); i++)
    {
        if (currentStreak >= 10 && maxLen < currentStreak)
        {
            maxLen = currentStreak;
            maxLenTeam = currentStreakTeam;
        }

        if (currentStreakTeam != linia[i])
        {
            if (currentStreak >= 10)
            {
                passy++;
            }
            currentStreak = 0;
            currentStreakTeam = linia[i];

        } // broken streak
        currentStreak++;
    }

    plik.close();

    cout << passy << " " << maxLen << " " << maxLenTeam;

    ofstream plik2;
    plik2.open("../wyniki/wyniki1.txt", ios::app);
    plik2 << passy << " " << maxLenTeam << " " << maxLen << endl;
    plik2.close();

    return 0;
}