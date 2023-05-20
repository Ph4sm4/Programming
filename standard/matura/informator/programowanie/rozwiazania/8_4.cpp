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
	vector<pair<int, int>> v; // value, longest increasing subsequence
	while (plik >> x) {
		v.push_back(make_pair(x, 1));
	}
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[j].first < v[i].first) {
				v[i].second = max(v[i].second, v[j].second + 1);
			}
		}
	}
	int mxDl = 0;
	for (int i = 0; i < v.size(); i++) {
		if (mxDl < v[i].second) mxDl = v[i].second;
	}

	cout << mxDl;

	plik.close();


	return 0;
}