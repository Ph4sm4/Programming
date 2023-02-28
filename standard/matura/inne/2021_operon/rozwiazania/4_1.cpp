#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int N = 101;
bool prime[N];

void sito()
{
    for (int i = 0; i < N; i++)
    {
        prime[i] = true;
    }
    prime[1] = false;
    for (int i = 2; i < sqrt(N); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{

    ifstream plik;
    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);
    plik.open("../dane/pary.txt");

    sito();

    int x;
    string y;
    while (plik >> x >> y)
    {
        if (x % 2 == 1)
            continue;

        for (int i = 2; i < N; i++)
        {
            if (prime[i] && prime[x - i])
            {
                cout << x << " " << i << " " << x - i << endl;
                plik2 << x << " " << i << " " << x - i << endl;
                break;
            }
        }
    }

    plik.close();
    plik2.close();

    return 0;
}
