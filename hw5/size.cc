#include <iostream>
using namespace std;

class size
{
	int a;
	char b;
	float c;
	double d;
	short e[5];
	char &f;
	double &g;
	static int h;
public:
	void show()
	{
		cout << "HELLO WORLD!" << endl;		
	}
	size() = default;
	~size(){};
};

int main()
{
	cout << sizeof(size) << endl;
	return 0;
}
