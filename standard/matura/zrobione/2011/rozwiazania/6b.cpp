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


int main() {

	ifstream plik;
	plik.open("../dane/liczby.txt");

	string linia;
	string maxNumber;
	

	while (getline(plik, linia)) {
		if (maxNumber.length() < linia.length()) maxNumber = linia;
		else if (maxNumber.length() == linia.length()) {
			bool isGreater = false;
			for (int i = 0; i < maxNumber.length(); i++) {
				if (maxNumber[i] - '0' > linia[i] - '0') break;
				else if (maxNumber[i] - '0' < linia[i] - '0') {
					isGreater = true;
					break;
				}
			}
			if (isGreater) {
				maxNumber = linia;
			}
		}
	}
	cout << maxNumber << endl;
	cout << toDec(maxNumber) << endl;

	plik.close();

	return 0;
}