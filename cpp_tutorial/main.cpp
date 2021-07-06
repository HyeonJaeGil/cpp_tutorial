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
// 리턴용 임시객체를 만들어 리턴한다.

int main()
{
    foo().x = 10;
    cout << p.x << endl;
}