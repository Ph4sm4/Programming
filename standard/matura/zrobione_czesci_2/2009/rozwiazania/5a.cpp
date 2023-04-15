#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

bool czyPalindrom(string x) {
	for (int i = 0; i < x.length() / 2; i++) {
		if (x[i] != x[x.length() - 1 - i]) return false;
	}

	return true;
}

int main() {

	ifstream plik;
	plik.open("../dane/dane.txt");

	int ct = 0;

	string w1, w2;
	while (plik >> w1 >> w2) {
		if (czyPalindrom(w1)) ct++;
		if (czyPalindrom(w2)) ct++;
	}
	cout << ct;

	plik.close();


	return 0;
}