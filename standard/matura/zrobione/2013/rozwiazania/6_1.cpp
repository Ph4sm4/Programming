#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <utility>
using namespace std;

int main() {

	ifstream plik;
	plik.open("../dane/dane.txt");

	int ct = 0;
	string linia;
	while (getline(plik, linia)) {
		if (linia[0] == linia[linia.length() - 1]) ct++;
	}
	cout << ct;

	plik.close();

	return 0;
}