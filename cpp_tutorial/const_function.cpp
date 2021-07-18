#include <iostream>
#include <cassert>

class Rect 
{
private:
	int left, top, right, bottom;

public:
	Rect(int a = 0, int b = 0, int c = 0, int d = 0)
		:left(a), top(b), right(c), bottom(d) {}

	//����Լ�
	int getArea() const { 
		assert(right >= left);
		assert(bottom >= top);
		return (right - left) * (bottom - top); }
};

//��ü�� const reference�� �����޴� �Լ��� ����ؼ�, ����Լ��� const�� ����� ����Լ��� ������ �Ѵ�.
void foo(const Rect& r) { int area = r.getArea(); std::cout << area << std::endl; }

int main()
{
	Rect r(1, 1, 10, 10);

	foo(r);
	return 0;

}