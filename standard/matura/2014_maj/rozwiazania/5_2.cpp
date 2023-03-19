#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


int main() {

	ifstream plik;
	plik.open("../dane/NAPIS.txt");

	string linia;

	while (getline(plik, linia)) {
		int last = int(linia[0]);
		bool good = true;
		for (int i = 1; i < linia.length(); i++) {
			if (int(linia[i]) < last) {
				good = false;
				break;
			}
			else {
				last = int(linia[i]);
			}
		}
		if (good) cout << linia << endl;

	}

	plik.close();


	return 0;
}