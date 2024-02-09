#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{

    cout << "Podaj liczbe: ";
    int n;
    cin >> n;

    string x = to_string(n);

    int sum = 0;
    for (int i = 0; i < x.length(); i++)
    {
        sum += pow((x[i] - '0'), x.length());
    }

    cout << boolalpha << (sum == n);

    return 0;
}