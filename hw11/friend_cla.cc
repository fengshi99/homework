#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
class Line;
class Point
{
public:
	friend Line;
	Point(int x,int y)
		:_x(x)
		 ,_y(y){}
	~Point() = default;
	void print();
private:
	int _x;
	int _y;
};
void Point::print()
{
	cout << "(" << _x << "," << _y << ")" << endl;
}
class Line
{
public:
	Line(Point& p1,Point& p2)
		:_p1(p1)
		 ,_p2(p2){}
	~Line() = default;
	void Length();
private:
	Point _p1;
	Point _p2;
};
void Line::Length()
{
	cout << "Length:" << hypotf((_p1._x - _p2._x),(_p1._y - _p2._y)) << endl;
}
int main()
{
	Point p1(2,3);
	Point p2(7,5);
	Line l(p1,p2);
	l.Length();
	return 0;
}
