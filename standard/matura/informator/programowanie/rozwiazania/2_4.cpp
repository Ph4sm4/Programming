#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {

	ifstream plik;
	plik.open("../dane/dane2_4.txt");
	string linia;

	while (plik >> linia) {
		int count = 0;
		for (int i = 0; i < linia.length(); i++) {
			if (linia[i] == '[') count++;
			else count--;
		}
		cout << (count == 0 ? "tak" : "nie") << endl;
	}

	plik.close();

	return 0;
}