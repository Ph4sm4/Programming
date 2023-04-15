#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <string>
using namespace std;

bool czyPalindrom(string x) {
	int l = 0, p = x.length() - 1;
	while (l < p) {
		if (x[l] != x[p]) return false;
		l++;
		p--;
	}
	return true;
}


int main() {

	ifstream plik;
	plik.open("../dane/slowa.txt");

	ofstream plik2, plik3;
	plik2.open("hasla_b.txt");
	plik3.open("slowa_b.txt");

	string linia;
	int suma = 0;
	string maxPass = "";
	string minPass = "";
	int maxLen = 0, minLen = INT_MAX;

	while (getline(plik, linia)) {
		string temp = linia;
		int index = linia.length() - 1;
		if (!czyPalindrom(temp)) {
			string t = temp;
			while (index >= 0 && !czyPalindrom(temp.erase(index--, 1)));
		}
		string password;
		if (temp.length() == linia.length()) password = linia;
		else {
			string rest = linia.substr(index, linia.length() - index);
			string restInverted = "";
			for (int i = rest.length() - 1; i >= 0; i--) {
				restInverted += rest[i];
			}
			password = restInverted + temp + rest;
		}
		plik2 << password << endl;
	
		if (password.length() == 12) plik3 << password << endl;
		if (maxLen < password.length()) {
			maxPass = password;
			maxLen = password.length();
		}
		if (minLen > password.length()) {
			minPass = password;
			minLen = password.length();
		}
		suma += password.length();
	}

	plik3 << maxPass << " " << minPass << endl;
	plik3 << suma << endl;

	plik2.close();
	plik3.close();
	plik.close();



	return 0;
}