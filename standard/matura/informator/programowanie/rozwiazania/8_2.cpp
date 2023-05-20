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
	plik.open("../dane/dane8.txt");

	int x;
	vector<int> v;
	while (plik >> x) {
		v.push_back(x);
	}
	int par = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] > v[j]) par++;
		}
	}
	cout << par;

	plik.close();


	return 0;
}