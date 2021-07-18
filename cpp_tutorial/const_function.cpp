#include <iostream>
#include <cassert>

class Rect 
{
private:
	int left, top, right, bottom;

public:
	Rect(int a = 0, int b = 0, int c = 0, int d = 0)
		:left(a), top(b), right(c), bottom(d) {}

	//상수함수
	int getArea() const { 
		assert(right >= left);
		assert(bottom >= top);
		return (right - left) * (bottom - top); }
};

//객체를 const reference로 참조받는 함수를 대비해서, 멤버함수에 const를 사용해 상수함수로 만들어야 한다.
void foo(const Rect& r) { int area = r.getArea(); std::cout << area << std::endl; }

int main()
{
	Rect r(1, 1, 10, 10);

	foo(r);
	return 0;

}