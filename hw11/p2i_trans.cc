#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Point
{
public:
	Point(int x =0,int y =0)
		:_x(x)
		 ,_y(y){}
	~Point() = default;
	void print();
	operator int();
private:
	int _x;
	int _y;
};
void Point::print()
{
	cout << "(" << _x << "," << _y << ")" << endl;
}
Point::operator int()
{
	return _x;
}
int main()
{
	Point p(2,3);
	p.print();
	int a = p;
	cout << a << endl;
	return 0;
}
