#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int main() {

	ifstream plik;
	plik.open("../dane/galerie_przyklad.txt");

	vector<pair<int, string>> v;
	string kraj, miasto;
	string temp;

	while (plik >> kraj >> miasto) {
		bool found = false;
		int index;
		for(int i = 0; i < v.size(); i++) {
			if (v[i].second == kraj) {
				found = true;
				index = i;
				break;
			}
		}
		if (found) {
			v[index].first++;
		}
		else {
			v.push_back(make_pair(1, kraj));
		}
		getline(plik, temp);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " " << v[i].first << endl;
	}

	plik.close();



	return 0;
}