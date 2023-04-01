#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

int toDec(string x) {
	int output = 0;
	int p = 0;
	for (int i = x.length() - 1; i >= 0; i--) {
		if (x[i] == '1') {
			output += pow(2, p);
		}
		p++;
	}
	return output;
}

string toBin(int x) {
	string notReversed = "";
	while (x) {
		notReversed += to_string(x % 2);
		x /= 2;
	}
	string output = "";
	for (int i = notReversed.length() - 1; i >= 0; i--) {
		output += notReversed[i];
	}
	return output;
}


int main() {

	ifstream plik;
	plik.open("../dane/liczby.txt");

	string linia;
	int ct = 0;

	int sumDec = 0;
	while (getline(plik, linia)) {
		if (linia.length() == 9) {
			sumDec += toDec(linia);
			ct++;
		}
	}
	cout << ct << endl;
	cout << toBin(sumDec) << endl;

	plik.close();

	return 0;
}