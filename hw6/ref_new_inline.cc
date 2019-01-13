#include <iostream>
using std::cout;
using std::endl;
using std::cin;

inline
void change(int &n)
{	
	int *p = new int(18);
	n = *p;
	delete p;
}

int main()
{
	int n = 10;
	cout << "now n is " << n << endl;
	change(n);
	cout << "now n is " << n << endl;
	return 0;
}
