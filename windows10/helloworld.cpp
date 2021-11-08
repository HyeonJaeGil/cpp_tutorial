#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base
{
public:
    Base(){cout << "Base constructor\n";}
    virtual ~Base(){cout << "Base destructor\n";}
};


class Derived : public Base{
public:
    Derived(){cout << "Derived constructor\n";}
    ~Derived(){cout << "Derived destructor\n";}
};



int main()
{

    return 0;
}