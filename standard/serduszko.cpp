#include <iostream>
#include <math.h>
using namespace std;

void printXSpaces(int x)
{
    for (int i = 0; i < x; i++)
        cout << " ";
}

int main()
{
    int n;
    cout << "Podaj nieparzyste n (n >= 3): ";
    cin >> n;

    if (n < 3 || n % 2 == 0)
    {
        cout << "Wrong n";
        return 1;
    }

    const int numberOfRowsUnderMain = ceil(float(n) / 3.0f);

    // spaces for the first row
    printXSpaces(numberOfRowsUnderMain);
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    printXSpaces(n - 2);
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;

    // the rest rows which are going downwards

    for (int i = 0; i < numberOfRowsUnderMain; i++)
    {
        printXSpaces(numberOfRowsUnderMain - 1 - i); // from wall
        cout << "*";
        printXSpaces(n + i * 2); // miedzy pierwszym wybrzuszeniem
        cout << "*";
        printXSpaces(n - (i + 1) * 2);
        cout << "*";
        printXSpaces(n + i * 2);
        cout << "*";
        cout << endl;
    }

    return 0;
}