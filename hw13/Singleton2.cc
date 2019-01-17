#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::cin;
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if(nullptr == _pInstance)
		{
			_pInstance = new Singleton();
			::atexit(destroy);
		}
		return _pInstance;
	}
	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}
private:
	static Singleton* _pInstance;
};
Singleton* Singleton::_pInstance = nullptr;
int main()
{
	Singleton *p = Singleton::GetInstance();
	return 0;
}
