#include "Password.h"

Password::Password(int length, bool contains_Numbers, bool contains_Letters, string letterType, char specialSigns) {
	this->length = length;
	this->contains_Numbers = contains_Numbers;
	this->contains_Letters = contains_Letters;
	if (tolower(specialSigns) == 'y') this->specialSigns = true;
	else this->specialSigns = false;

	if (letterType == "b") letType = big;
	else if (letterType == "s") letType = small;
	else letType = both;

	if (check()) GeneratePassword();
}

Password::~Password() {}

string Password::GetPassword() const {
	return password;
}

bool Password::check() {
	if (!contains_Letters && !contains_Numbers && !specialSigns || length == 0) return false;
	return true;
}

void Password::GeneratePassword() {
	cout << "Generating..." << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));

	for (int i = 0; i < length; i++) {
		random = getGoodRandom();
		switch (random) {
		case 0: { //special signs
			int version = rand() % 2;
			switch (version) {
			case 0: {
				password += char(rand() % 15 + 33);
				break;
			}
			case 1: {
				password += char(rand() % 7 + 58);
				break;
			}
			}
			break;
		}
		case 1: { //letters
			switch (letType) {
			case small: {//small
				password += char(rand() % 26 + 97);
				break;
			}
			case big: {//big
				password += char(rand() % 26 + 65);
				break;
			}
			case both: {//both
				int version = rand() % 2;
				switch (version) {
				case 0: {//small
					password += char(rand() % 26 + 97);
					break;
				}
				case 1: {//big
					password += char(rand() % 26 + 65);
					break;
				}
				}
				break;
			}
			}
			break;
		}
		case 2: { //numbers
			password += (rand() % 10) + '0';
			break;
		}
		}
	}
}

int Password::getGoodRandom() const {
	bool is_good = false;
	do {
		random = rand() % 3;
		switch (random)
		{
		case 0: {
			if (specialSigns) is_good = true;
			break;
		}
		case 1: {
			if (contains_Letters) is_good = true;
			break;
		}
		case 2: {
			if (contains_Numbers) is_good = true;
			break;
		}
		}
	} while (!is_good);

	return random;
}