#include <iostream>
#include "Dummy.cpp"

int g_value = 1;

int returnValue()
{
	int value = 3;
	std::cout << "address of value: " << &value;
	return value;
}

int& returnReference() {
	std::cout << "address of g_value: " << &::g_value << std::endl;
	return ::g_value;
}


int main() 
{
	Dummy d{ 10 };
	int value1 = 1;

	std::cout << d.getValue() << std::endl;
	std::cout << d.getReference(value1) << std::endl;

	int value2 = d.getReference(value1);
	int value3 = d.getReference(value1);
	std::cout << "value2: " << &value2 << " value3: " << &value3 << std::endl;

	const int &value4 = d.getValue();
	int& value5 = d.getReference(value1);
	std::cout << "value4: " << &value4 << " value5: " << &value5 << std::endl;

	std::cout << &(d.getReference(value1)) << std::endl;

	int test1 = 5;
	int test2 = test1;

	int& test3 = test1;

	std::cout << "test1: " << &test1 << " test2: " << &test2 << " test3: " << &test3 << std::endl;

	returnReference() = 6;
	std::cout << returnReference() << std::endl;
	std::cout << "g_value: " << g_value;

	return 0;
}