#pragma once
#include <string>
#include <iostream>
#include <thread>
using namespace std;

enum letterType { small, big, both };

class Password {
	unsigned int length;
	bool contains_Numbers;
	bool contains_Letters;
	bool specialSigns;
	letterType letType;
	string password = "";
	void GeneratePassword();
	bool check();
	mutable int random;
	int getGoodRandom() const;
public:
	explicit Password(int length, bool contains_Numbers, bool contains_Letters, string letterType, char specialSigns);
	~Password();
	string GetPassword() const;
};

