#pragma once

#include <assert.h>
#include <iostream>

template <typename T, unsigned int T_SIZE>
class myArray
{
private:
	/*int m_length;
	T m_data[T_size];*/
	T* m_data;

public:
	myArray()
	{
		m_data = new T [T_SIZE];
	}

	T& operator [] (int index) 
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}


	int getLength() 
	{
		return T_SIZE;
	}

	auto print() 
	{
		for (int i = 0; i < T_SIZE; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

};