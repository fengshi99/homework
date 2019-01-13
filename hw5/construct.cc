#include <iostream>
using namespace std;

class point
{
public:
	point();
	explicit 
		point(int ix);
	point(int ix,int iy);
	~point(){};
	int x;	
	int y;
};
point::point()
{
	x = 0;
	y = 0;
}
point::point(int ix)
{
	x = ix;
	y = 0;
}
point::point(int ix,int iy)
{
	x = ix;
	y = iy;
}

int main()
{
	point p1(2);
	point p2(2,3);
	point p3 = 6;		// use explicit to stop implicit conversion
	cout << p1.x << p1.y <<endl;
	cout << p2.x << p2.y <<endl;
	cout << p3.x << p3.y <<endl;
	return 0;
}
