#include <iostream>
#include "CustomException.h"

int main() {

	try
	{
		throw ChildCustomException();
	}
	catch (const CustomException& exception)
	{
		std::cout << "CustomException Catch!" << std::endl;
		std::cout << typeid(exception).name() << std::endl;
		std::cerr << exception.what() << std::endl;
	}
	
	catch (const ChildCustomException & exception)
	{
		std::cout << "ChildCustomException Catch!" << std::endl;
		std::cout << typeid(exception).name() << std::endl;
		std::cerr << exception.what() << std::endl;
	}
	return 0;
}