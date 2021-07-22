#include <iostream>

class Base {
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;

public:
	int getPublicValue() const { return m_public; }
	int getProtectedValue() const { return m_protected; }
	int getPrivateValue() const { return m_private; }
};

class Derived_public  : public Base
{ 
public:
	Derived_public()
	{
		m_public = 1;
		m_protected = 2;
		//m_private = 3; // m_private is private for the Base, Derived class cannot modify it.
	}

	using Base::m_protected;	 //make m_protected public in here.

private:
	int getPublicValue() = delete; //make getPublicValue unavailable in this class. 

};

class Derived_protected : protected Base
{
public:
	Derived_protected()
	{
		m_public = 1;
		m_protected = 2;
		//m_private = 3;
	}
};

class Derived_private : private Base
{
public:
	Derived_private()
	{
		m_public = 1;
		m_protected = 2;
		//m_private = 3;
	}
};

class Derived_Derived_private : public Derived_private 
{
public:
	Derived_Derived_private() {
		// m_public and m_protected are private for Derived_private: 
		// child class of Derived_private(Derived_Derived_private) cannot use it.
		/*m_public = 1; 
		m_protected = 2;*/	
	}
};


int main() {

	Derived_public D1;
	Derived_protected D2;
	Derived_private D3;
	Derived_Derived_private D4;

	D1.m_public;	
	D1.m_protected; // OK thanks to using Base::m_protected in the public:  section of Derived_public.
	// D1.getPublicValue(); // error because of "delete"
	D1.Base::getProtectedValue();
	D1.getPrivateValue();

	//D2.Base::getProtectedValue();

	//D2.m_public;
	// D3.m_public;
	// D4.m_public;

	return 0;
}