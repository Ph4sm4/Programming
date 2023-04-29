#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
	
	ifstream plik;
	plik.open("../dane/dane1_3.txt");
	int x;
	int suma = 0;
	int maxSuma = 0;

	while (plik >> x) {
		if (suma < 0) suma = 0;
		suma += x;
		if (maxSuma < suma) maxSuma = suma;
	}
	cout << maxSuma << endl;

	plik.close();

	return 0;
}