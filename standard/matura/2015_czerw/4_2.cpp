#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    fstream plik;
    plik.open("piastek.txt", ios::in);

    int totalK = 0, totalO = 0, totalM = 0;
    int k, o, m;

    while (plik >> k >> o >> m)
    {
        totalK += k;
        totalO += o;
        totalM += m;
    }
    const int total = totalK * 685 + totalO * 620 + totalM * 380;
    cout << total;

    plik.close();

    return 0;
}