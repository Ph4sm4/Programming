#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> k >> n;

    list<int> l;
    for (int i = 1; i <= k; i++)
    {
        l.push_back(i);
    }
    decltype(l)::iterator it = l.begin();
    advance(it, n - 1);
    int ct = 0;
    while (l.size() != 1)
    {
        if (it == l.end())
            it = l.begin();
        if (!(ct % n))
        {
            decltype(it) temp = l.erase(it);
            it = temp;
        }
        else
        {
            it++;
        }
        ct++;
    }
    decltype(l)::const_iterator _Start = l.begin();
    cout << *_Start;
    return 0;
}