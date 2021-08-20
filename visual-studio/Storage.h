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

// double �ڷ����� ���� template Ư��ȭ ����
template <>
void Storage<double>::print() 
{
	std::cout << "Double type : ";
	std::cout << m_value << std::endl;
}