#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Point
{
public:
	friend void  Reset(Point& p,int x,int y);
	Point(int x,int y)
		:_x(x)
		 ,_y(y)
			{}
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
void Reset(Point& p,int x,int y)
{
	p._x = x;
	p._y = y;
}
int main()
{
	Point p(2,3);
	p.print();
	Reset(p,5,6);
	p.print();
	return 0;	
}
