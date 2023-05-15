#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

struct Przedzial {
	int pocz, kon;
	int dl;
	Przedzial(pocz, kon, dl) : pocz(pocz), kon(kon), dl(dl) { }
};

bool zawierasie(Przedzial& a, Przedzial& b) {
	return a.pocz >= b.pocz && a.kon <= b.kon;
}

int main() {

	ifstream plik;
	plik.open("../dane/dane3.txt");
	int a, b;
	vector<Przedzial> v;
	while (plik >> a >> b) {
		v.push_back(Przedzial(a, b, 1));
	}
	sort(v.begin(), v.end(), [](Przedzial a, Przedzial b)->bool {
		return (a.kon - a.pocz + 1) < (b.kon - b.pocz + 1);
		});
	/*for_each(v.begin(), v.end(), [](pair<int, int> a) {
		cout << a.first << " " << a.second << " " << a.second - a.first + 1 << endl;
		});*/
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (zawierasie(v[j], v[i]) {
				if(v[i])
			}
			
		}
		m.insert(make_pair(przedzial, ct));
	}
	

	plik.close();

	return 0;
}