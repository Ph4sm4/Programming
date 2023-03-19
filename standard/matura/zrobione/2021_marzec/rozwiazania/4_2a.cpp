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

	vector<pair<pair<int, int>, string>> v;
	string temp, miasto;
	int x, y;
	int ct = 0;
	int suma = 0;
	int liczbaLokali = 0;
	while (plik >> temp) {
		ct++;
		if (ct == 2) miasto = temp;

		if (ct == 143) {
			v.push_back(make_pair(make_pair(suma, liczbaLokali), miasto));
			suma = 0;
			liczbaLokali = 0;
			ct = 1;
		}
		else if (ct > 2) {
			if (ct % 2 == 1) {
				x = stoi(temp);
			}
			else {
				y = stoi(temp);
				suma += x * y;
				if (x != 0 && y != 0) {
					liczbaLokali++;
				}
			}
		}

	}
	v.push_back(make_pair(make_pair(suma, liczbaLokali), miasto));
	suma = 0;
	liczbaLokali = 0;
	ct = 1;
	pair<string, int> mx;
	pair<string, int> mn;
	mx.second = 0;
	mn.second = INT_MAX;
	for (int i = 0; i < v.size(); i++) {
		if (mn.second > v[i].first.first) {
			mn.first = v[i].second;
			mn.second = v[i].first.first;
		}
		if (mx.second < v[i].first.first) {
			mx.first = v[i].second;
			mx.second = v[i].first.first;
		}
	}

	cout << mx.first << " " << mx.second << endl;
	cout << mn.first << " " << mn.second << endl;

	plik.close();



	return 0;
}