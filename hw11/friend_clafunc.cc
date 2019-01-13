#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
class Point;
class Line
{
public:
	void distance(Point& p1,Point& p2);
};
class Point
{
public:
	friend void Line::distance(Point& p1,Point& p2);
	Point(int x,int y)
		:_x(x)
		 ,_y(y){}
	~Point() = default;
private:
	int _x;
	int _y;
};
void Line::distance(Point& p1,Point& p2)
{
	cout << "Distance:" << hypotf(p1._x - p2._x,p1._y - p2._y) << endl;
}
int main()
{
	Point p1(2,3);
	Point p2(5,8);
	Line l;
	l.distance(p1,p2);
	return 0;
}
