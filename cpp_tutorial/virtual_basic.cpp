#include <iostream>

using std::cout;
using std::endl;

class A {
public:
	virtual void print() { cout << "A" << endl; }
	//void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public B {
public:
	void print() { cout << "C" << endl; }
};

class D  : public C{
public:
	void print() { cout << "D" << endl; }
};

//int main() {
//
//	A a;
//	B b;
//	C c;
//	D d;
//
//	// If parent's member function is virtual ,
//	// parent class ptr (ref_a) to child class instance utilize child class's member function.
//	// If parent's member function is not virtual ,
//	// parent class ptr (ref_a) to child class instance utilize parent class's member function.
//	A* ref_a = &b;
//	ref_a->print();
//
//	// Even B - C has no explicit virtual keyword,
//	// as A (hierarchally Top class) has virtual keywords in the member function,
//	// parent class ptr (ref_b) to child class instance utilize child class's member function.
//	C* ref_b = &c;
//	ref_b->print();
//
//	return 0;
//}