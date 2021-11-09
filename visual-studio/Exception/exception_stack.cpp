#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

void first();
void second();
void third();
void last();

int main() {

	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		std::cerr << "Main Caught int exception" << endl;
	}
	
	cout << "End main" << endl;
	return 0;
}


void first() {

	cout << "First" << endl;
	try
	{
		second();
	}
	catch (int)
	{
		cerr << "first caught int exception" << endl;
	}
}

void second() {

	cout << "Second" << endl;
	try
	{
		third();
	}
	catch (double)
	{
		cerr << "second caught double exception" << endl;
	}
}

void third() {

	cout << "Third" << endl;
	last();
	cout << "Third finished" << endl;
}

void last() {

	cout << "Last" << endl;
	cout << "Throws exception" << endl;

	throw - 1;

	cout << "end last" << endl;
}