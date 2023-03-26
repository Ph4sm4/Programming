#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <utility>
using namespace std;


int main() {

	ifstream plik;
	plik.open("../dane/NAPIS.txt");

	string linia;
	map<string, int> s;
		
	while (getline(plik, linia)) {
		pair<map<string, int>::iterator, bool> success = s.insert(make_pair(linia, 1));
		if (!success.second) {
			success.first->second++;
		}
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		if (it->second > 1) {
			cout << it->first << endl;
		}
	}

	plik.close();


	return 0;
}