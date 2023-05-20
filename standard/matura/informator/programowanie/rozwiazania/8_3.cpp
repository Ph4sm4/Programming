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
	int dl = 1;
	int mxDl = 1;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] < v[i + 1]) dl++;
		else dl = 1;

		if (mxDl < dl) mxDl = dl;
	}
	
	cout << mxDl;

	plik.close();


	return 0;
}