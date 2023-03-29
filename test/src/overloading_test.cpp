#include <iostream>

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents = 0) { m_cents = cents; }

    void operator + (const Cents & c2) 
    {
	    std::cout << m_cents + c2.m_cents << std::endl;
    }

    void operator () ()
    {
	    this->m_cents;
    }
    void operator () (int cents) 
    {
	    this->m_cents = cents;
	    std::cout << m_cents << std::endl;
    }
};


int main()
{
    Cents cents1(5);
    Cents cents2(7);

    cents1 + cents2; // 12 출력
    cents1.operator+(cents2);
    cents1(3);
}

