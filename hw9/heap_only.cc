#include <iostream>
#include <string.h>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::cin;
class Phone
{
public:
	void destory()
	{
		delete this;
	}

	Phone(const char* brand,float price)
		:_brand(new char[strlen(brand)+1]())
		 ,_price(price)
	{
		strcpy(_brand,brand);
	}
private:
	char *_brand;
	float _price;
	~Phone() = default;

};

int main()
{
	//Phone phone("apple",5555);//error
	Phone *phone = new Phone("apple",5555);
	phone -> destory();
	return 0;
}
