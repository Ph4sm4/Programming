#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main() {

	string kresk[] = { "10101110111010", "11101010101110", "10111010101110", "11101110101010", "10101110101110", "11101011101010", "10111011101010", "10101011101110", "11101010111010", "10111010111010" };

	ifstream plik;

	plik.open("../dane/kody.txt");
	string x;


	while (getline(plik, x)) {
		int it = 0;
		int sumNiep = 0;
		int sumParz = 0;
		for (int i = x.length() - 1; i >= 0; i--) {
			if (it % 2 == 0) {
				sumParz += (x[i] - '0');
			}
			else {
				sumNiep += (x[i] - '0');
			}
			it++;
		}
		int sum = sumNiep + sumParz;
		int cyfrKontr = (10 - (sum % 10)) % 10;

		cout << x << " " << cyfrKontr << " " << kresk[cyfrKontr] << endl;
	}



	plik.close();



	return 0;
}