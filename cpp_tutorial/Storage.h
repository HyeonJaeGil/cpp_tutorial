#pragma once
#include <iostream>

template <class T>
class Storage
{
private:
	T m_value;

public:
	Storage(T value)
	{
		m_value = value;
	}

	void print() 
	{
		std::cout << m_value << '\n';
	}
};

// double 자료형을 위한 template 특수화 구현
template <>
void Storage<double>::print() 
{
	std::cout << "Double type : ";
	std::cout << m_value << std::endl;
}