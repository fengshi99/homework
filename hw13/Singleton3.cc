#include <iostream>
#include <stdlib.h>
#include <pthread.h>
using std::cout;
using std::endl;
using std::cin;
pthread_once_t once = PTHREAD_ONCE_INIT;
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		pthread_once(&once,once_run);
		return _pInstance;
	}	
	static void once_run()
	{	
		if(nullptr == _pInstance)
		{
			_pInstance = new Singleton();
			::atexit(destroy);
		}
			
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
