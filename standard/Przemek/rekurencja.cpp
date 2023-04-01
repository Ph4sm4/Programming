#include <iostream>
#include <string>
using namespace std;

int silnia(int n);
int fibonacci(int n);

int main()
{
    for (;;)
    {
        int n;
        cout << "Podaj n: ";
        cin >> n;
        cout << fibonacci(n) << endl;
        cout << silnia(n) << endl;
    }

    return 0;
}

// 1. Napisz program, który obliczy n wartość ciagu fibonacciego
// 2. Napisz program, ktory oblicz silnie z n

int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return fibonacci(n - 2) + fibonacci(n - 1);
}

int silnia(int n)
{
    if (n == 0)
        return 1;

    return n * silnia(n - 1);
}
