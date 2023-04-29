#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {

	ifstream plik;
	plik.open("../dane/dane2_3.txt");
	string linia;
	
	while (plik >> linia) {
		int glebokosc = 0;
		int mxGlebokosc = 0;
		for (int i = 0; i < linia.length(); i++) {
			if (linia[i] == '[') glebokosc++;
			else glebokosc--;
			if (mxGlebokosc < glebokosc) mxGlebokosc = glebokosc;
		}
		cout << mxGlebokosc << endl;
	}

	plik.close();

	return 0;
}