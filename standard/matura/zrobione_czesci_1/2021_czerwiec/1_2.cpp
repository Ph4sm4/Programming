#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int dl = 0;
    while (n)
    {
        int odejmij = 0;
        while (odejmij * odejmij < n)
        {
            odejmij++;
        }
        if (odejmij * odejmij > n)
        {
            odejmij--;
        }
        n -= odejmij * odejmij;
        dl++;
    }
    cout << dl;

    return 0;
}