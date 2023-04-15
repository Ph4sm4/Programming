#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <utility>
using namespace std;

string to_dec(string x) {
	int output = 0;
	int p = 0;
	for (int i = x.length() - 1; i >= 0; i--) {
		if (x[i] - '0' != 0) {
			output += pow(8, p) * (x[i] - '0');
		}
		p++;
	}
	return to_string(output);
}

int main() {

	ifstream plik;
	plik.open("../dane/dane.txt");

	int ct = 0;
	string linia;
	int mxDec = 0;
	string mx;
	int mnDec = INT_MAX;
	string mn;

	while (getline(plik, linia)) {
		string temp = to_dec(linia);
		int tempInt = stoi(temp);
		int prev = linia[0] - '0';
		bool good = true;
		for (int i = 1; i < linia.length(); i++) {
			if (prev > linia[i] - '0') {
				good = false;
				break;
			}
			prev = linia[i] - '0';
		}
		if (good) {
			if (mxDec < tempInt) {
				mxDec = tempInt;
				mx = linia;
			}
			if (mnDec > tempInt) {
				mnDec = tempInt;
				mn = linia;
			}
			ct++;
		}
	}
	cout << ct << " max: " << mx << " min: " << mn;

	plik.close();

	return 0;
}