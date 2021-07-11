#include "Resource.h"
#include "AutoPtr.h"
#include <memory>

using std::cout;
using std::endl;

int main()
{
	// AutoPtr<Resource> res1(new Resource(1000000));
	// std::unique_ptr<Resource> res1(new Resource(100));
	std::unique_ptr<Resource> res1 = std::make_unique<Resource>(100);
	auto res1 = std::make_unique<Resource>(100);

	cout << &res1 << endl;

	// AutoPtr<Resource> res2(res1);
	// AutoPtr<Resource> res2(std::move(res1));
	AutoPtr<Resource> res2;

	// res2 = res1;


	cout << &res1 << endl;
	cout << &res2 << endl;


}