#include <iostream>

using namespace std;

int main() {

	int x = 65;
	auto long_x = long(x);

	cout << &x << " and " << &long_x << endl;


	return 0;
}