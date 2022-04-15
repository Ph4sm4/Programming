#include <bits/stdc++.h>
#include "printSTL.h"
using namespace std;

class Funktor
{
public:
    int pole;
    int operator()(int a) const
    {
        return a * a;
    }
};

int main()
{
    Funktor f, f1;
    cout << f(10) << endl;
    cout << f1(20) << endl;
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> v2;
    transform(v.begin(), v.end(), back_inserter(v2), bind(multiplies<int>(), placeholders::_1, 10));
    printSTL(v2, " ");
    replace_if(v2.begin(), v2.end(), bind(greater_equal<int>(), placeholders::_1, 40), 99);
    printSTL(v2, " ");

    v2.erase(
        remove_if(v2.begin(), v2.end(),
                  bind(logical_and<int>(),
                       bind(greater_equal<int>(), placeholders::_1, 40),
                       bind(less_equal<int>(), placeholders::_1, 99))),
        v2.end());

    printSTL(v2, " ");

    return 0;
}