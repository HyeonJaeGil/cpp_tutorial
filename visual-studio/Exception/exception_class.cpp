#include <iostream>
#include "MyArray.h"


int main() {

	//int input[3] = { 1,2,3 };
	//MyArray myarray(input);

	MyArray myarray;

	try
	{
		myarray[100];
	}
	catch (const int & x)
	{
		std::cerr << "Exception " << x << std::endl;
	}

	return 0;
	
};