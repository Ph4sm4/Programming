#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

string szyfruj(string x, int klucz) {
	string output = "";
	for(int i = 0; i < x.length(); i++) {
		int c = x[i];
		
		if (c + klucz > 90) {
			output += char(c + klucz - 26);
		}
		else {
			output += char(c + klucz);
		}
	}
	
	return output;
}

int main() {

	ifstream plik;

	const int K = 107 % 26;

	plik.open("../dane/dane_6_1.txt");
	string linia;
	while (getline(plik, linia)) {
		cout << szyfruj(linia, K) << endl;
	}


	plik.close();


	return 0;
}