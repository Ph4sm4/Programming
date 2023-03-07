#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


vector<int> czyLucky;
void sito() {
	for (int i = 0; i < 10100; i++) czyLucky[i] = i;

	int wykresl = 2;
	for (int i = 1; i < 10100; i++) {
		for (int j = 1; j < 10100; j += wykresl) {
			czyLucky[j] = false; // trzeba stworzyc taka sama liste i po kolei z niej usuwac te wartosci, bo skaczemy co np 3, ale po tych ktore jeszcze sa, a nie ogolem!!
		}
		for (int j = i + 1; j < 10100; j++) {
			if (czyLucky[j]) {
				wykresl = j;
				break;
			}
		}
	}
}

int main() {

	ifstream plik;
	plik.open("../dane/dane.txt");

	sito();
	int x;
	int ct = 0;
	for(int i = 1; i <= 261; i++) {
		if (czyLucky[i]) {
			cout << i << " ";
		}
	}

	plik.close();



	return 0;
}