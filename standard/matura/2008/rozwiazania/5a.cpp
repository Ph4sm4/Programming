#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
using namespace std;


int main() {
	
	ifstream plik;
	plik.open("../dane/slowa.txt");

	ofstream plik2, plik3;
	plik2.open("hasla_a.txt");
	plik3.open("slowa_a.txt");
	
	string linia;
		
	pair<string, int> maxPass = { "", 0 };
	pair<string, int> minPass = { "", INT_MAX };

	while (getline(plik, linia)) {
		string temp = "";
		for (int i = linia.length() - 1; i >= 0; i--) {
			temp += linia[i];
		}
		plik2 << temp << endl;
		if (temp.length() > maxPass.second) {
			maxPass.first = temp;
			maxPass.second = temp.length();
		}
		if (temp.length() < minPass.second) {
			minPass.first = temp;
			minPass.second = temp.length();
		}
	}

	plik3 << maxPass.first << " " << maxPass.second << endl;
	plik3 << minPass.first << " " << minPass.second << endl;
	

		plik2.close();
	plik3.close();
	plik.close();



	return 0;
}