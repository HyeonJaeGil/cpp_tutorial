#include <iostream>

using std::cout; using std::endl;

struct Point
{
    int x, y;
};

Point p = { 1, 2 };

Point foo()
{
    return p;
}
// ���Ͽ� �ӽð�ü�� ����� �����Ѵ�.

int main()
{
    foo().x = 10;
    cout << p.x << endl;
}