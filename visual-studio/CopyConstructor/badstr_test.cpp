#include <iostream>
#include "stringbad.h"

void callme1(StringBad&);
void callme2(StringBad);

int main() {

	std::cout << "start\n";
	StringBad headline1("First headline");
	StringBad headline2("Second headline");
	StringBad headline3("Third headline");

};