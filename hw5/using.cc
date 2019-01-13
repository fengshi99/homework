#include <iostream>
using namespace std;

class Base
{
public:
	size_t size()
	{
		cout << "OK!I am now in! " << n << endl;
		return n;
	}
protected:
	size_t n = 1024;
};

class Derived:private Base
{
public:
	using Base::size; // break the private
protected:
	using Base::n;
};

int main()
{
	Derived d;
	d.size();
	return 0;
}
