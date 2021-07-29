#include <iostream>
#include <vector>
//#include <functional>
using std::cout;
using std::endl;

class Base {
public:
	virtual void print() {
		cout << "Base" << endl;
	}
};

class Derived : public Base {
	virtual void print() {
		cout << "Derived" << endl;
	}
};

int main() {

	Base b;
	Derived d;

	// std::vector<Base> vec; //slicing occurs
	// std::vector<Base&> vec; //impossible

	std::vector<std::reference_wrapper<Base>> vec;
	vec.push_back(b);
	vec.push_back(d);

	for (auto& element : vec)
		// element.print();
		element.get().print();

	return 0;
}