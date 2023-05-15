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
	plik.open("../dane/dane4.txt");

	int x;
	vector<int> v;
	while (plik >> x) v.push_back(x);

	int maxI = 0;
	int maxPar = 0;
	for (int i = 1; i < v.size(); i++) {
		int par = 0;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) par++;
		}
		if (maxPar < par) {
			maxPar = par;
			maxI = i;
		}
	}
	cout << maxI + 1 << endl;


	plik.close();


	return 0;
}