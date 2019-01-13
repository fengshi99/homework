#include <iostream>
#include <math.h>
using std::cout;
using std::endl;
using std::cin;
double square(int n)
{
	return sqrt(n); 
}


int main()
{
	int n;
	cout << "input:";
	cin >> n;
	cout << "before trans:" << square(n)<<endl;
	cout << "after trans:" << static_cast<int>(square(n)) <<endl; 	
	return 0;
}
