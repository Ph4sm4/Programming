#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <utility>
using namespace std;

string to_dec(string x) {
	int output = 0;
	int p = 0;
	for (int i = x.length() - 1; i >= 0; i--) {
		if (x[i] - '0' != 0) {
			output += pow(8, p) * (x[i] - '0');
		}
		p++;
	}
	return to_string(output);
}

int main() {

	ifstream plik;
	plik.open("../dane/dane.txt");

	int ct = 0;
	string linia;
	while (getline(plik, linia)) {
		string temp = to_dec(linia);
		if (temp[0] == temp[temp.length() - 1]) ct++;
	}
	cout << ct;

	plik.close();

	return 0;
}