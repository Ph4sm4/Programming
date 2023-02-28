#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >> a;

    int b = 0;
    int i = 1;
    int sum1 = 0, sum2 = 0;

    for (;;)
    {
        if (i >= a)
        {
            b = sum1 - 1;
            break;
        }

        if (a % i == 0 && i < a)
        {
            sum1 += i;
        }
        i++;
    }
    i = 1;

    for (;;)
    {
        if (i >= b && sum2 - 1 != a)
        {
            cout << "NIE";
            exit(0);
        }
        else if (i >= b)
            break;

        if (b % i == 0 && i < b)
        {
            sum2 += i;
        }
        i++;
    }
    cout << b;

    return 0;
}