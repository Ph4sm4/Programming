#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int bin_to_dec(string x)
{
    int sum = 0;
    int p = 0;
    for (int i = x.length() - 1; i >= 0; i--)
    {
        if ((x[i] - '0'))
            sum += pow(2, (x[i] - '0') * p);
        p++;
    }
    return sum;
}

int getSecsFromTime(string time)
{
    string hours = time.substr(0, 5);
    string minutes = time.substr(6, 5);
    string secs = time.substr(12, 5);

    int sec = 0;
    sec += (((hours[0] - 65)) * 6 + bin_to_dec(hours.substr(1, 4))) * 3600;
    sec += (((minutes[0] - 65)) * 15 + bin_to_dec(minutes.substr(1, 4))) * 60;
    sec += ((secs[0] - 65)) * 15 + bin_to_dec(secs.substr(1, 4));

    return sec;
}

int main()
{
    ifstream plik;
    plik.open("./dane/kopalnia.txt");

    string linia;
    getline(plik, linia);

    string time, weight;

    int prevVal;

    int startSec = 0;
    int endSec = 0;

    int goodStart = 0;
    int goodEnd = 0;

    while (plik >> time >> weight)
    {
        int kwarta = (int)weight[0] - 64;
        // 0 - 249, 250 - 499, 500 - 749, 750 - 999
        string binWeight = weight.substr(1, weight.length() - 1);
        int actualWeight = (kwarta - 1) * 250 + bin_to_dec(binWeight);

        if (startSec == 0)
        {
            startSec = getSecsFromTime(time);
        }

        if (!prevVal)
        {
            startSec = getSecsFromTime(time);
        }
        else if (abs(prevVal - actualWeight) <= prevVal * 0.05)
        {

            endSec = getSecsFromTime(time);
        }
        else if (abs(prevVal - actualWeight) > prevVal * 0.05 && abs(prevVal - actualWeight) <= prevVal * 0.1)
        {
            if (goodEnd - goodStart < endSec - startSec)
            {
                goodStart = startSec;
                goodEnd = endSec;
            }
            startSec = 0;
        }
        else if (abs(prevVal - actualWeight) > prevVal * 0.1)
        {
            if (goodEnd - goodStart < endSec - startSec)
            {
                goodStart = startSec;
                goodEnd = endSec;
            }
            startSec = 0;
        }

        prevVal = actualWeight;
    }
    int len = goodEnd - goodStart;
    string lH = to_string(len / 3600);
    len %= 3600;
    string lM = to_string(len / 60);
    len %= 60;
    string lS = to_string(len % 60);

    while (lH.length() < 2)
        lH.insert(0, "0");
    while (lM.length() < 2)
        lM.insert(0, "0");
    while (lS.length() < 2)
        lS.insert(0, "0");

    plik.close();

    ofstream plik2;
    plik2.open("./wyniki/wyniki1.txt", ios::app);

    plik2 << "1.2." << lH << ":" << lM << ":" << lS << endl;

    plik2.close();

    // 30 minut
    return 0;
}