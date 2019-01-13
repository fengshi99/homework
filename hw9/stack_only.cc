#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;

class Phone
{
public:
	Phone(const char* brand,float price)
		:_brand(new char[strlen(brand)+1]())
		 ,_price(price)
	{}
	~Phone() = default;
private:
	char* _brand;
	float _price;
	void* operator new(size_t size)
	{
		return (Phone*)malloc(size);
	}
	void operator delete(void *ptr)
	{
		free(ptr);
	}
};
int main()
{
	Phone phone("HTC",5656);
	return 0;
}
