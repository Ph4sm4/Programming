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
	int parz = 0;
	int nparz = 0;
	for (int i = 1; i < v.size(); i++) {
		if (abs(v[i - 1] - v[i]) % 2 == 0) parz++;
		else nparz++;
	}
	cout << parz << " " << nparz << endl;

	plik.close();


	return 0;
}