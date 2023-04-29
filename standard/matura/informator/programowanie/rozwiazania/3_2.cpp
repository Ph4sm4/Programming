#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <map>
using namespace std;

int main() {

	ifstream plik;
	plik.open("../dane/dane3.txt");
	int a, b;
	vector<pair<int, int>> v;
	while (plik >> a >> b) {
		v.push_back(make_pair(a, b));
	}
	// dlugosc, ilosc
	map<int, int> m;
	for (auto p : v) {
		int dl = p.second - p.first + 1;
		auto res = m.insert({ dl, 1 });
		if (res.second == false) {
			m[dl]++;
		}
	}
	int mxDl = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (mxDl < it->second) mxDl = it->first;
	}
	cout << mxDl;
	plik.close();

	return 0;
}