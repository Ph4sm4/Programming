#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

bool isAnagram(string base, string look) {
	for (int i = 0; i < base.length(); i++) {
		bool found = false;
		for (int j = 0; j < look.length(); j++) {
			if (look[j] == base[i]) {
				found = true; 
				break;
			}
		}
		if (!found) return false;
	}

	return true;
}

int main() {

	ifstream plik;
	plik.open("../dane/anagram.txt");

	string w1, w2, w3, w4, w5;
	while (plik >> w1 >> w2 >> w3 >> w4 >> w5) {
		string anagram = w1;
		if (isAnagram(anagram, w2) && isAnagram(anagram, w3) && isAnagram(anagram, w4) && isAnagram(anagram, w5)) {
			cout << w1 << " " << w2 << " " << w3 << " " << w4 << " " << w5 << endl;
		}
		
	}

	plik.close();

	return 0;
}