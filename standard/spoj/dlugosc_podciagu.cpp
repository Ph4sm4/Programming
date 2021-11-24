#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	
	cout << "Podaj liczbe zestawow: ";
	unsigned int zestawy;
	cin >> zestawy;
	vector<int> c;

	for (int i = 0; i < zestawy; i++) {
		int dl, dl2;
		string slowo, slowo2;
		cout << "Dlugosc 1 slowa: ";
		cin >> dl;
		cout<<"Podaj 1 slowo: ";
		cin >> slowo;
		cout << "Podaj dlugosc 2 slowa: ";
		cin >> dl2;
		cout << "Podaj 2 slowo: ";
		cin >> slowo2;

		double m = max(slowo.length(), slowo2.length());
		double count = 0;
		
		for (int j = 0; j < m; j++) {
			for (int g = 0; g < m; g++) {
				if (slowo[j] == slowo2[g]) {
					count++;
				}
			}
		}
		c.push_back(ceil(count/2));
	}
	for (int i : c) {
		cout << i << endl;
	}

}