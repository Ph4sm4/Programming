#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

bool czyAntypalindrom(string x) {
	for (int i = 0; i < x.length() /2; i++) {
		if (x[i] == x[x.length() - 1 - i]) return false;
	}

	return true;
}

int main() {

	ifstream plik;
	plik.open("../dane/dane6.txt");

	string linia;
	while (plik >> linia) {
		if (czyAntypalindrom(linia)) {
			cout << linia << endl;
		}
	}


	plik.close();

	return 0;
}