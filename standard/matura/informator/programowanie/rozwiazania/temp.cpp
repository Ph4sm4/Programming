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

	string a, b;
	cin >> a >> b;
	int l = min(a.length(), b.length());
	string output = "";
	int lastInd = 0;
	string longer = a.length() >= b.length() ? a : b;
	string shorter = a.length() < b.length() ? a : b;
	for (int i = 0; i < l; i++) {
		for (int j = lastInd; j < longer.length(); j++) {
			if (shorter[i] == longer[j]) {
				output += shorter[i];
				lastInd = j;
				break;
			}
		} 
	}
	if (output.length() == 0) cout << 0;
	else cout << output << " " << output.length();


	return 0;
}