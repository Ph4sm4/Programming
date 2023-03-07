#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main() {

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
		cout << x << " " << sumParz << " " << sumNiep << endl;
	}



	plik.close();



	return 0;
}