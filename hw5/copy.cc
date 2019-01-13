#include <iostream>
#include <cstring>
using namespace std;

class com
{
public:
	com(const char *c)	
	{
		b = new char[strlen(c)+1];
		strcpy(b,c);
		cout << "calling constructor" << endl;
	};
	
	~com()
	{
	
		cout << "calling"<< *b <<  "destructor" << endl;
	delete []b;
	};
	com(const com &nc)
	{
		b = new char[strlen(nc.b)+1];
		strcpy(b,nc.b);
	    cout << "calling copy construcotr" << endl;
	};
private:
	char *b;
};
com fun()
{
	return com("adv");
}
int main()
{
	com a("LENOVO");
	com b = a;
	com c = com("DELL");
	cout << "after temp" << endl;

	return 0;
}
