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
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " " << v[i].first.first << " " << v[i].first.second << endl;
	}

	plik.close();



	return 0;
}