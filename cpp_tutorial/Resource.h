#pragma once
#include <iostream>

class Resource 
{
private:
	int m_size;
	int m_data[];

public:
	Resource() 
		:m_size(100)
	{
		std::cout << "Resource default constructor" << std::endl;
	}

	Resource(int size)
		:m_size(size)
	{
		std::cout << "Resource length constructor" << std::endl;
	}

	~Resource()
	{
		std::cout << "Resource destructor" << std::endl;
	} 

	Resource(const Resource& a) 
	{
		std::cout << "Resource copy constructor" << std::endl;
	}

};