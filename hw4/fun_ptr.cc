#include <iostream>
using namespace std;

int add(int x,int y)
{
	return x+y;
}
int sub(int x,int y)
{
	return x-y;
}
int (*fun)(int x,int y);

int main()
{
	fun = &add;
	cout << "when fun = add :" <<(*fun)(4,9) << endl;
	fun = &sub;
	cout << "when fun = sub :" << (*fun)(9,3) << endl;
	return 0;
}
