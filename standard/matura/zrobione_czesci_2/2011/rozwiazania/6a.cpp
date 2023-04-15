#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


int main() {

	ifstream plik;
	plik.open("../dane/liczby.txt");

	int ct = 0;
	string linia;
	while (getline(plik, linia)) {
		if (linia[linia.length() - 1] == '0') ct++;
	}
	cout << ct;

	plik.close();

	return 0;
}