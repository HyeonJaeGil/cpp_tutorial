#include "Storage.h"


template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}


template <>
char getMax(char x, char y)
{
	std::cout << "Comparing chars" << std::endl;
	return (x > y) ? x : y;

}


/*int main()
{
	std::cout << getMax('a', 'b') << std::endl;

	Storage<int> intValue(5);
	Storage<double> doubleValue(6.45555);

	intValue.print();
	doubleValue.print();
}*/