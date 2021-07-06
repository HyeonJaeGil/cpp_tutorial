#include "Resource.h"
#include "AutoPtr.h"

using std::cout;
using std::endl;

int main()
{
	AutoPtr<Resource> res1(new Resource(1000000));

	cout << &res1 << endl;

	AutoPtr<Resource> res2(res1);

	cout << &res1 << endl;
	cout << &res2 << endl;


}