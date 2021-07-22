#pragma once

#include <string>
#include <iostream>

class Person 
{
private:
	std::string m_name;

public:
	Person(const std::string& name_in = "No name")
		:m_name(name_in) {}

	void setName(const std::string & name_in) 
	{
		m_name = name_in;
	}

	std::string getName() const 
	{
		return m_name;
	}

};