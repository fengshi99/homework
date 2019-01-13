#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Point
{
private:
	int _x;
	int _y;
public:
	Point() = default;
	Point(int x,int y):_x(x),_y(y){}
	~Point(){}
	Point(const Point& P){
		_x = P._x;
		_y = P._y;
		cout << "calling copy constructor! " << endl; 
	}
	Point& operator=(const Point&);
	void print()
	{
		cout << _x << "." << _y << endl;
	}
};
Point& Point::operator=(const Point& P)
{
	cout << "calling operator= " << endl;
	_x = P._x;
	_y = P._y;
	return (*this);
}

int main()
{
	Point p1(2,6);
	
	Point p2 = p1;
	p2.print();
	
	Point p3 = Point(3,4);
	p3.print();

	p3 = p2;
	p3.print();
	
	return 0;
}
