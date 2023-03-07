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
	vector<int> powierzchnie;

	pair<string, int> minUnikalne = {"", INT_MAX };
	pair<string, int> maxUnikalne = {"", 0 };

	while (plik >> temp) {
		ct++;
		if (ct == 2) miasto = temp;

		if (ct == 143) {
			v.push_back(make_pair(make_pair(suma, liczbaLokali), miasto));
			suma = 0;
			liczbaLokali = 0;
			if (minUnikalne.second > powierzchnie.size()) {
				minUnikalne.second = powierzchnie.size();
				minUnikalne.first = miasto;
			}
			if (maxUnikalne.second < powierzchnie.size()) {
				maxUnikalne.second = powierzchnie.size();
				maxUnikalne.first = miasto;
			}
			ct = 1;
			powierzchnie.clear();
		}
		else if (ct > 2) {
			if (ct % 2 == 1) {
				x = stoi(temp);
			}
			else {
				y = stoi(temp);
				suma += x * y;
				int powierzchnia = x * y;
				bool found = false;
				for (int i = 0; i < powierzchnie.size(); i++) {
					if (powierzchnie[i] == powierzchnia) {
						found = true;
						break;
					}
					
				}
				if (!found && powierzchnia != 0) {
					powierzchnie.push_back(powierzchnia);
				}
				
				if (x != 0 && y != 0) {
					liczbaLokali++;
				}
			}
		}

	}
	cout << maxUnikalne.first << " " << maxUnikalne.second << endl;
	cout << minUnikalne.first << " " << minUnikalne.second << endl;

	plik.close();



	return 0;
}