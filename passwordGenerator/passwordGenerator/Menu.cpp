#include "Menu.h"

void Menu::Display() {
	int len;
	cout << "Enter length of your password: ";
	cin >> len;
	cout << "Do you want to have numbers in your password (y / n): ";
	char temp;
	bool numbers, letters, bigSmall;
	cin >> temp;
	if (tolower(temp) == 'y') numbers = true;
	else numbers = false;
	cout << "Do you want to have letters in your password (y / n): ";
	cin >> temp;
	string big_small;
	if (tolower(temp) == 'y') {
		letters = true;
		cout << "What type of letters do you want (b-big, s-small, both-bth): ";
		cin >> big_small;
	}
	else letters = false;

	cout << "Do you want to include special signs (y / n): ";
	char specialSigns;
	cin >> specialSigns;

	Password password(len, numbers, letters, big_small, specialSigns);

	cout << (password.GetPassword() == "" ? "COULDN'T GENERATE A PASSWORD" : "Your password is: " + password.GetPassword()) << endl;
}