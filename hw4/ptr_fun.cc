#include <iostream>
using namespace std;
int z;
int* fun(int x,int y)
{
	z = x+y;
	int* result = &z;
	return result;
}

int main()
{
	int* result = fun(4,9);
	cout <<"result is " << *result << endl;
	return 0;
}
