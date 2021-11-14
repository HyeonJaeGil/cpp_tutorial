#include <iostream>

class Dummy
{
private:
	int m_value;
public:
	void setValue(const int& value) { m_value = value; }
	int getValue() const { return m_value; }
	int& getReference(int& input) { return m_value; }

	Dummy()
		: m_value(0)
	{}

	Dummy(int value)
		: m_value(value)
	{}

	Dummy(const Dummy& copy)
	{
		std::cout << "Copy constructor" << std::endl;
		this->m_value = copy.m_value;
	}
};

