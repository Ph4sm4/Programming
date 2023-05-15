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
	plik.open("../dane/dane6.txt");

	vector<pair<int, pair<string ,int >>> v; // system, liczba p minimalna z 
	// najwieksza suma cyfr i jej suma cyfr
	for (int i = 2; i <= 10; i++) {
		v.push_back(make_pair(i, make_pair("", 0)));
	}
	string linia;
	vector<string> liczby;
	while (plik >> linia) liczby.push_back(linia);

	for_each(v.begin(), v.end(), [liczby, v](pair<int, pair<string, int >>& a)->void {
		int system = a.first;
		for (int i = 0; i < liczby.size(); i++) {
				string x = liczby[i];
				bool good = true;
				bool oneLessP = false;
				int sumCyfr = 0;
				for (int j = 0; j < x.length(); j++) {
					if (x[j] - '0' >= system) {
						good = false;
						break;
					}
					if (x[j] - '0' + 1 == system) {
						oneLessP = true;
					}
					sumCyfr += (x[j] - '0');
				}
				if (good && oneLessP && sumCyfr > a.second.second) {
					a.second.second = sumCyfr;
					a.second.first = x;
				}
			}
		});
	for_each(v.begin(), v.end(), [](pair<int, pair<string, int >> a)->void {
		cout << a.first << " " << a.second.first << endl;
		});

	plik.close();

	return 0;
}