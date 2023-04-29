#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
using namespace std;

int main() {

	ifstream plik;
	plik.open("../dane/dane3.txt");
	int a, b;
	vector<pair<int, int>> v;
	while (plik >> a >> b) {
		v.push_back(make_pair(a, b));
	}
	int mxDl1 = INT_MAX;
	int mxDl2 = INT_MAX;
	for (auto p : v) {
		int dl = p.second - p.first + 1;
		if (mxDl1 > dl) mxDl1 = dl;
	}
	for (auto p : v) {
		int dl = p.second - p.first + 1;
		if (mxDl2 > dl && mxDl1 != dl) mxDl2 = dl;
	}
	cout << mxDl1 << " " << mxDl2;
	plik.close();

	return 0;
}