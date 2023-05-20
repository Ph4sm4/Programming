#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int main() {

	ifstream plik;
	plik.open("../dane/szyfrogram.txt");

	string linia;
	map<char, int> m;
	while (plik >> linia) {
		for (int i = 0; i < linia.length(); i++) {
			auto res = m.insert(make_pair(linia[i], 1));
			if (res.second == false) {
				m[linia[i]]++;
			}
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}


	plik.close();


	return 0;
}