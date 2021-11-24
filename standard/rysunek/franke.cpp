#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cout << "Podaj liczbe kolumn: ";
	double wysokosc;
	try {
		cin >> wysokosc;
		int count = 0;
		int temp = wysokosc-1, z = wysokosc-1;
		if (wysokosc < 0) throw 10;
		else {
			for (int i = 0; i < wysokosc; i++) {
				count++;
				
				while(z >= 0){
					cout<<" ";
					z--;
				}
				temp--;
				z = temp;
				for(int j = 0; j < count+i; j++){
					cout<<".";
				}
				cout<<endl;
			}
		}
	}
	catch (int x) {
		cout << "Blad" << endl;
	}

	return 0;
}