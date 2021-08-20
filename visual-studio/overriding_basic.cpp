#include <iostream>

using std::cout;
using std::endl;

class A {
public:
	virtual void print(int x) { cout << "A" << endl; }
	virtual A* getThis() { return this; }
};

class B : public A {
public:
	// different parameter, so it cannot override.
	//virtual void print(short x) override { cout << "B" << endl; }
	void print(int x) override { cout << "B" << endl; }
	virtual B* getThis() { return this; }

};

//int main() {
//
//	A a;
//	B b;
//
//	A& ref = b;
//	b.getThis()->print(1);
//	ref.getThis()->print(2);
//
//	return 0;
//}


