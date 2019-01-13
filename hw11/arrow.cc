#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Point
{
public:
	void print();
	Point(int x =0,int y =0)
		:_x(x)
		 ,_y(y){}
	~Point() = default;
private:
	int _x;
	int _y;
};
void Point::print()
{
	cout << "(" << _x << "," << _y << ")" << endl;
}
class PointPtr
{
public:
	PointPtr()
	{
		p = new Point(0,0);
	}
	~PointPtr() = default;
	Point* operator->();
private:
	Point* p;
};
Point* PointPtr::operator->()
{
	return p;		
}
int main()
{
	PointPtr pptr;
	pptr->print();
	return 0;	
}
