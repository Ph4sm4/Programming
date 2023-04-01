#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {

	ifstream plik;
	plik.open("../dane/anagram.txt");

	string w1, w2, w3, w4, w5;
	while (plik >> w1 >> w2 >> w3 >> w4 >> w5) {
		if (w1.length() == w2.length() && w2.length() == w3.length() && w3.length() == w4.length() && w4.length() == w5.length()) {
			cout << w1 << " " << w2 << " " << w3 << " " << w4 << " " << w5 << endl;
		}
	}

	plik.close();

	return 0;
}