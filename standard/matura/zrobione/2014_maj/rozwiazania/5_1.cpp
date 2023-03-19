#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

bool prime[100000];
void sito() {
	for (int i = 0; i < 100000; i++) prime[i] = true;
	prime[1] = false;

	for (int i = 2; i < sqrt(100000); i++) {
		if (prime[i]) {
			for (int j = i * i; j < 100000; j += i) {
				prime[j] = false;
			}
		}
	}
}


int main() {

	ifstream plik;
	plik.open("../dane/NAPIS.txt");
	sito();

	string linia;
	int ct = 0;
	while (getline(plik, linia)) {
		int suma = 0;
		for (int i = 0; i < linia.length(); i++) {
			suma += int(linia[i]);
		}
		if (prime[suma]) ct++;
	
	}
	cout << ct;

	plik.close();


	return 0;
}