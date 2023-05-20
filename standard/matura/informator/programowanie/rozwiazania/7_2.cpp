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

	ifstream plik, plik2;
	plik.open("../dane/szyfrogram.txt");
	plik2.open("../dane/czestosc.txt");

	string linia;
	map<char, int> czestosc;
	map<char, int> m;

	char z;
	int x;
	while(plik2 >> z >> x) {
		czestosc.insert(make_pair(z, x));
		m.insert(make_pair(z, 0));
	}
	vector<string> t;
	while (plik >> linia) {
		for (int i = 0; i < linia.length(); i++) {
			m[linia[i]]++;
		}
		t.push_back(linia);
	}
	map<char, char> d; // to co w tekscie, faktyczne
	for (auto it = m.begin(); it != m.end(); it++) {
		for (auto it2 = czestosc.begin(); it2 != czestosc.end(); it2++) {
			if(it->second == it2->second) {
				d.insert(make_pair(it->first, it2->first));
			}
		}
	}
	for (string temp : t) {
		for (int i = 0; i < temp.length(); i++) {
			cout << d[temp[i]];
		}
		cout << endl;
	}



	plik.close();


	return 0;
}