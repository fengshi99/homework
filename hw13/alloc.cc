#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int main()
{
	char* cp = new char[5]()+4;
	cout << sizeof(cp) << endl;
	return 0;
}
