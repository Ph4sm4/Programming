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

bool czyZawiera(string a, string b) {
	if (a.find(b) != string::npos) return true;
	return false;
}

bool sprawdzPrefiks(string a, string b) {
	bool good = false;
	int longestPrefix = 0;
	for (int i = 0; i < b.length(); i++) {
		string substrX = a.substr(0, i + 1);
		string substrY = b.substr(b.length() - 1 - i, i + 1);
		if (substrX == substrY) {
			longestPrefix = substrX.length();
			good = true;
		};
	}
	return good;
}

bool sprawdzSufiks(string a, string b) {
	bool good = false;
	int longestSufix = 0;
	for (int i = 0; i < b.length(); i++) {
		string substrX = a.substr(a.length() - 1 - i, i + 1);
		string substrY = b.substr(0, i + 1);
		if (substrX == substrY) {
			longestSufix = substrX.length();
			good = true;
		}
	}
	
	return good;
}

string stworzC(string a, string b) {
	if (!sprawdzPrefiks(a, b) && !sprawdzSufiks(a, b)) return a + b;

	if (a.find(b) != string::npos || a.length() == b.length()) return a;

	string sufixC, prefixC;
	// sufixC
	int longestSufix = 0;
	for (int i = 0; i < b.length(); i++) {
		string substrX = a.substr(a.length() - 1 - i, i + 1);
		string substrY = b.substr(0, i + 1);
		if (substrX == substrY) {
			longestSufix = substrX.length();
		}
	}
	sufixC = a + b.substr(longestSufix, b.length() - longestSufix);

	// prefixC
	int longestPrefix = 0;
	for (int i = 0; i < b.length(); i++) {
		string substrX = a.substr(0, i + 1);
		string substrY = b.substr(b.length() - 1 - i, i + 1);
		if (substrX == substrY) {
			longestPrefix = substrX.length();
		}
	}
	prefixC = b.substr(0, b.length() - longestPrefix) + a;

	if (prefixC.length() < sufixC.length()) return prefixC;
	return sufixC;
}

int main() {

	ifstream plik;
	plik.open("../dane/dane.txt");

	string w1, w2;

	while (plik >> w1 >> w2) {
		cout << stworzC(w1, w2) << endl;
	}

	plik.close();


	return 0;
}