#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {

	ifstream plik;
	plik.open("../dane/dane1_4.txt");
	int x;
	int indexLewy, indexPrawy;
	int l, p = 0;
	int suma = 0;
	int maxSuma = 0;
	
	while (plik >> x) {
		if (suma < 0) {
			suma = 0;
			l = p;
		}
		suma += x;
		if (maxSuma < suma) {
			maxSuma = suma;
			indexLewy = l + 1;
			indexPrawy = p + 1;
		}
		p++;
	}
	
	cout << indexLewy << " " << indexPrawy;


	plik.close();

	return 0;
}