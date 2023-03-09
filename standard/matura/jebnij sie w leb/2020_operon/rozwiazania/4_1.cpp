#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


vector<int> czyLucky(10100);
void szczesliweSito() {
	for (int i = 0; i < 10100; i++) czyLucky[i] = i + 1;
	for (auto i = czyLucky.begin(); i < czyLucky.end(); i++) {
		if (*i % 2 == 0) {
			czyLucky.erase(i);
		}
	}
	vector<int> doWykreslenia;
	int wykresl;
	int index = 1;
	for (int i = 0; i < czyLucky.size(); i++) {
		wykresl = czyLucky[index++];
		for (int j = wykresl - 1; j < czyLucky.size(); j += wykresl) {
			doWykreslenia.push_back(czyLucky[j]);
		}
		for (int j = 0; j < doWykreslenia.size(); j++) {
			for (auto it = czyLucky.begin(); it < czyLucky.end(); it++) {
				if (*it == doWykreslenia[j]) {
					czyLucky.erase(it);
					break;
				}
			}
		}
		doWykreslenia.clear();
	}

}

bool isLucky(int x) {
	for (int i = 0; i < czyLucky.size(); i++) {
		if (czyLucky[i] == x) {
			return true;
		}
	}
	return false;
}

int main() {

	ifstream plik;
	plik.open("../dane/dane.txt");

	szczesliweSito();
	int ct = 0;
	int x;
	while (plik >> x) {
		if (isLucky(x)) {
			ct++;
		}
	}
	cout << ct;
	plik.close();



	return 0;
}