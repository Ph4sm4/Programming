#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{

    // Napisz program, który liczbę wpisaną z klawiatury, mniejszą niż 255, zapisze jako sumę potęg liczby 2.

    int x;
    cin >> x;

    int sum = 0;
    int i = 0;

    vector<int> v;
    while (sum != x)
    {
        if (sum + pow(2, i) <= x)
        {
            i++;
        }
        else
        {
            sum += pow(2, i - 1);
            v.push_back(pow(2, i - 1));
            i = 0;
        }
    }

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    return 0;
}