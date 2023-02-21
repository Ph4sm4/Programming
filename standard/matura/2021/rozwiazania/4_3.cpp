#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void dopisz(string& x, char a) {
	x += a;
}

void zmien(string& x, char a) {
	x[x.length() - 1] = a;
}

void usun(string& x) {
	x.erase(x.length() - 1);
}

void przesun(string& x, char a) {
	for (int i = 0; i < x.length(); i++) {
		if (x[i] == a) {
			int val = int(a);
			if (val + 1 <= 90) {
				x[i] = char(val + 1);
				break;
			}
			else {
				x[i] = 'A';
				break;
			}
		}
	}
}

int main() {

	ifstream plik;
	plik.open("../dane/instrukcje.txt");

	string linia;
	char x;

	vector<pair<int, int>> v;

	while (plik >> linia >> x) {
		if (linia == "DOPISZ") {
			bool found = false;
			int index = -1;
			for (int i = 0; i < v.size(); i++) {
				if (v[i].first == x) {
					found = true;
					index = i;
					break;
				}
			}

			if (!found) {
				pair<int, int> temp;
				temp.first = x;
				temp.second = 1;
				v.push_back(temp);
			}
			else {
				v[index].second++;
			}
		}
	}
	char litera;
	int maxCount = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i].second > maxCount) {
			maxCount = v[i].second;
			litera = v[i].first;
		}
	}

	cout << litera << " " << maxCount << endl;

	plik.close();


	return 0;
}