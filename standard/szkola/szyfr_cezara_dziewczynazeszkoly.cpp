#include <iostream>
using namespace std;

int main()
{
    string pol, zd;
    int kl;
    cin >> pol;
    cin >> kl;
    cin.ignore();
    getline(cin, zd);
    int d = zd.size();
    string szyfr = "";
    if (pol == "szyfruj")
    {
        for (int i = 0; i < d; i++)
        {
            int b = int(zd[i]);
            if (b >= 97 && b <= 122)
            {
                b = kl + b;
                if (b > 122)
                {
                    b = b - 26;
                }
            }

            if (b >= 65 && b <= 90)
            {
                b = kl + b;
                if (b > 90)
                {
                    b = b - 26;
                }
            }
            szyfr = szyfr + char(b);
        }
    }
    else
    {
        for (int i = 0; i < d; i++)
        {
            int b = int(zd[i]);
            if (b >= 97 && b <= 122)
            {
                b -= kl;
                if (b < 97)
                {
                    b += 26;
                }
            }else if (b >= 65 && b <= 90)
            {
                b -= kl;
                if (b < 65)
                {
                    b += 26;
                }
            }

            
            szyfr += char(b);
        }
    }

    cout << szyfr;
}