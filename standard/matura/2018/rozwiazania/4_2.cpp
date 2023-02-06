#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

int main()
{

    ifstream plik;
    plik.open("../dane/sygnaly.txt");

    string x;
    string output;
    int maxDiff = 0;

    while (plik >> x)
    {
        vector<int> v;
        for (int i = 0; i < x.length(); i++)
        {
            bool found = false;
            for (int j = 0; j < v.size(); j++)
            {
                if (x[i] == v.at(j))
                    found = true;
            }
            if (!found)
                v.push_back(x[i]);
        }
        if (maxDiff < v.size())
        {
            maxDiff = v.size();
            output = x;
        }
    }
    cout << output << " " << maxDiff << endl;
    ofstream plik2;
    plik2.open("wyniki4.txt", ios::app);
    plik2 << output << " " << maxDiff << endl;

    plik2.close();

    plik.close();

    return 0;
}