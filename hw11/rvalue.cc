#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Point
{
public:
	Point(int i =0)
		:_i(i){}
	~Point()
	{
		cout << "point" << _i << " now is destructing" << endl;
	}
	Point& operator=(const Point&);
	void print();
private:
	int _i;
};
Point& Point::operator=(const Point& p)
{
	this->_i = p._i;
	return *(this);
}
void Point::print()
{
	cout << "Point" << _i << endl;
}
Point GetPoint()
{
	static int i=0;
	return Point(i++);
}
void func(Point& p)
{
	p.print();
}
int main()
{
	Point p(8);
	(GetPoint() = p).print();
	Point p2 = GetPoint();
	p2.print();
	func(GetPoint() = GetPoint());
	cout << "----" << endl;
	return 0;
}
