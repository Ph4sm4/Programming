#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

bool sprawdz(string a, string b) {
	int przesuniecie;
	if (int(a[0]) > int(b[0])) {
		przesuniecie = abs(int(a[0]) - int(b[0]) - 26);
	}
	else {
		przesuniecie = abs(int(a[0]) - int(b[0]));
	}
	for (int i = 0; i < a.length(); i++) {
		if (int(a[i]) > int(b[i]) && abs(int(a[i]) - int(b[i]) - 26) != przesuniecie ||
			int(a[i]) <= int(b[i]) && abs(int(a[i]) - int(b[i])) != przesuniecie) {
			return false;
		}

	}

	return true;
}

int main() {

	ifstream plik;

	plik.open("../dane/dane_6_3.txt");
	ofstream plik2;
	plik2.open("wyniki3.txt");
	string a, b; 
	while (plik >> a >> b) {
		if (!sprawdz(a, b)) {
			plik2 << a << endl;
		}
		
	}

	plik2.close();
	plik.close();


	return 0;
}