#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int oct_to_dec(string x)
{
    int sum = 0;
    int p = 1;
    for (int i = x.length() - 1; i >= 0; i--)
    {
        int z = (x[i] - '0');
        sum += z * pow(8, p) / 8;
        p++;
    }
    return sum;
}

string dec_to_bin(int x)
{
    string val = "";
    while (x)
    {
        val += to_string(x % 2);
        x /= 2;
    }
    string output = "";
    for (int i = val.length() - 1; i >= 0; i--)
        output += val[i];

    while (output.length() < 4)
        output.insert(0, "0");

    return output;
}

string translateTime(string time)
{
    int h = oct_to_dec(time.substr(0, 2));
    int m = oct_to_dec(time.substr(3, 2));
    int s = oct_to_dec(time.substr(6, 2));

    string outH = char((h / 6) + 65) + dec_to_bin(h % 6);
    string outM = char((m / 15) + 65) + dec_to_bin(m % 15);
    string outS = char((s / 15) + 65) + dec_to_bin(s % 15);

    string out = outH + ":" + outM + ":" + outS;
    return out;
}

string translateWeight(string weight)
{
    int d = oct_to_dec(weight);

    return char((d / 250) + 65) + dec_to_bin(d % 250);
}

int main()
{
    ifstream plik;
    plik.open("./dane/fabryka.txt");

    string linia;
    getline(plik, linia);

    string time, weight;

    ofstream plik2;
    plik2.open("./wyniki/wyniki1.txt", ios::app);

    while (plik >> time >> weight)
    {
        plik2 << "1.3." << translateTime(time) << " " << translateWeight(weight) << endl;
    }

    plik2.close();
    plik.close();

    // 30 minut
    return 0;
}