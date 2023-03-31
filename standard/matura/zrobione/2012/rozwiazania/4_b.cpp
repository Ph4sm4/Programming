#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
using namespace std;

string zaszyfruj(string x, string klucz) {
	string output = "";
	int index = 0;
	for (int i = 0; i < x.length(); i++) {
		int c = int(x[i]) + (int(klucz[index++]) - 64);
		if (c > 90) {
			output += char(c - 26);
		}
		else {
			output += char(c);
		}

		if (index == klucz.length()) index = 0;
	}

	return output;
}

string deszyfruj(string x, string klucz) {
	string output = "";
	int index = 0;
	for (int i = 0; i < x.length(); i++) {
		int c = int(x[i]) - (int(klucz[index++]) - 64);
		if (c < 65) {
			output += char(c + 26);
		}
		else {
			output += char(c);
		}

		if (index == klucz.length()) index = 0;
	}

	return output;
}

int main() {

	ifstream plik, plik2;
	plik.open("../dane/sz.txt");
	plik2.open("../dane/klucze2.txt");

	vector<pair<string, string>> v;

	string linia;
	while (getline(plik, linia))
		v.push_back(make_pair(linia, ""));

	int index = 0;
	while (getline(plik2, linia))
	{
		v.at(index++).second = linia;
	}

	for (int i = 0; i < v.size(); i++) {
		cout << deszyfruj(v.at(i).first, v.at(i).second) << endl;
	}

	plik.close();
	plik2.close();


	return 0;
}