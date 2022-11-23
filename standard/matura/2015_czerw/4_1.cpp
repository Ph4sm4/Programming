#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    fstream plik;
    plik.open("piastek.txt", ios::in);

    int kostka = 0, orzech = 0, mial = 0;
    int k, o, m;

    int day = 15;
    int i = 10;
    bool dluzszy;

    while (plik >> k >> o >> m)
    {
        dluzszy = (i - (i < 6 ? 0 : 7)) % 2;
        if (i == 13)
            i = 1;

        if (i == 2 && day == 29)
        {
            cout << kostka << " " << orzech << " " << mial << endl;
            kostka = 0;
            orzech = 0;
            mial = 0;
            day = 1;
            i++;
        }
        else if (day == 31 && !dluzszy)
        {
            cout << kostka << " " << orzech << " " << mial << endl;
            kostka = 0;
            orzech = 0;
            mial = 0;
            day = 1;

            i++;
        }
        else if (day == 32 && dluzszy)
        {
            cout << kostka << " " << orzech << " " << mial << endl;
            kostka = 0;
            orzech = 0;
            mial = 0;
            day = 1;

            i++;
        }

        kostka += k;
        orzech += o;
        mial += m;
        day++;
    }
    cout << kostka << " " << orzech << " " << mial << endl;

    plik.close();

    return 0;
}