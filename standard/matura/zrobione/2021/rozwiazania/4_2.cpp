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

	string output = "";

	string last = "";
	int maxLen = 0;
	int len = 1;

	while (plik >> linia >> x) {
		if (last.length() == 0) last = linia;
		
		if (linia == last) {
			len++;
		}
		else {
			len = 1;
		}
		if (maxLen < len) {
			output = linia;
			maxLen = len;
		}
		last = linia;
	}
	cout << output << " " << maxLen << endl;

	plik.close();


	return 0;
}