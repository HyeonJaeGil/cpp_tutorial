#include <cstring>
#include "stringbad.h"
#define _CRT_SECURE_NO_WARNINGS

int StringBad::num_strings = 0;

StringBad::StringBad(const char* s) {

	len = strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	std::cout << num_strings << ": " << str
		<< " instance created\n";
}
	
StringBad::StringBad() {
		len = 4;
		str = new char[len + 1] ;
		std::strcpy(str, "C++");
		num_strings++;
		std::cout << num_strings << ": " << str
		<< " default instance created\n";

}

StringBad::~StringBad() {
	std::cout << str << "instance destructed";
	--num_strings;
	std::cout << "Instance left: " << num_strings << "\n";
	delete[] str;
}

std::ostream& operator<< (std::ostream& os, const StringBad& st) {
	os << st.str;
	return os;
}
