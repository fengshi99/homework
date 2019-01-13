#include <iostream>
using namespace std;

class sta
{
public:
	static int  price;
	int number;
	static void show();
	static void print(sta &N);
	sta(int n):number(n){};
	~sta(){};
};
int sta::price = 5000;
void sta::show()
{
	cout << price << endl;
}
void sta::print(sta &N)
{
	cout << N.price << endl;
	cout << N.number << endl;
}
int main()
{
	sta s1(4000);
	s1.show();
	s1.print(s1);
	return 0;
}
