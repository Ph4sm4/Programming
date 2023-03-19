#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

string rozszyfruj(string x, int klucz) {
	string output = "";
	for (int i = 0; i < x.length(); i++) {
		int c = x[i];

		if (c - klucz < 65) {
			output += char(c - klucz + 26);
		}
		else {
			output += char(c - klucz);
		}
	}

	return output;
}

int main() {

	ifstream plik;

	plik.open("../dane/dane_6_2.txt");
	string wyraz;
	int klucz;
	while (plik >> wyraz >> klucz) {
		cout << rozszyfruj(wyraz, klucz % 26) << endl;
	}


	plik.close();


	return 0;
}