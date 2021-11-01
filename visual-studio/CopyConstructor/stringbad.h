#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma once

class StringBad {

private:
	char* str;
	int len;
	static int num_strings;

public:
	StringBad(const char* s);
	StringBad();
	~StringBad();

	friend std::ostream& operator<< (std::ostream& os, const StringBad& st);
};