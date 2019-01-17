#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if(nullptr == _pInstance)
			_pInstance = new Singleton();
		return _pInstance;
	}
//	void destroy()
//	{
//		if(_pInstance)
//			delete _pInstance;
//	}
private:
	class AutoRelease
	{
	public:
		AutoRelease() = default;
		~AutoRelease()
		{
			if(_pInstance)
				delete _pInstance;
		}
	};
	static Singleton* _pInstance;
	static AutoRelease _AS;
};
Singleton* Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_AS;
int main()
{
	Singleton *p = Singleton::GetInstance();
	return 0;
}
