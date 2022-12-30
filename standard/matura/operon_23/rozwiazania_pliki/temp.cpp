#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    float c1 = sqrt(pow(a, 2) + pow(b, 2));
    float c2 = sqrt(pow(b, 2) - pow(a, 2));
    float c3 = sqrt(pow(a, 2) - pow(b, 2));

    int c;
    if (c1 == int(c1))
        c = c1;
    else if (c2 == int(c2))
        c = c2;
    else if (c3 == int(c3))
        c = c3;
    else
    {
        cout << 0;
        exit(0);
    }
    int x = 1;

    while (x * a <= 1000 && x * b <= 1000 && x * c <= 1000)
    {
        vector<int> temp = {x * a, x * b, x * c};
        if (x != 1)
            cout << "pierwotne ";
        sort(temp.begin(), temp.end());
        copy(temp.begin(), temp.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        x++;
    }

    return 0;
}