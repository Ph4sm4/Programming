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
	plik.open("../dane/dane3.txt");
	int a, b;
	vector<pair<int, int>> v;
	while (plik >> a >> b) {
		v.push_back(make_pair(a, b));
	}
	
	
	plik.close();

	return 0;
}