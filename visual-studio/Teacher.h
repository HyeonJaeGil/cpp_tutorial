#pragma once
#include "Person.h"

class Teacher :public Person
{
private:

public:
	Teacher(const std::string& name_in = "No Name")
		:Person(name_in) {}

	friend std::ostream& operator << (std::ostream& out, const Teacher& teacher) 
	{
		out << teacher.getName();
		return out;
	}
};