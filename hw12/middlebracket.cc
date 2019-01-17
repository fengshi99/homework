 ///
 /// @file    middlebracket.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-01-14 16:42:07
 ///
 
#include <string.h>

//#include <string>

#include <iostream>
using std::cout;
using std::endl;

//arrry.operator[](0);
int array[10] = {1, 2, 3};

class CharArray
{
public:
	CharArray(size_t sz = 10)
	: _sz(sz)
	, _data(new char[_sz]())
	{
		cout << "CharArray(size_t)" << endl;
	}

	//下标访问运算符,有两个参数
	//第一个操作数是对象本身、第二个操作数可以是任意类型
	//
	//string/vector 他们都能像使用数组一样去访问元素，就是因为他们重载了下标访问运算符
	char & operator[](size_t idx) 
	{
		if(idx < size()) {
			return _data[idx];
		} 
		else {
			static char nullchar = '\0';		
			return nullchar;
		}
	}

	~CharArray()
	{
		cout << "~CharArray()" << endl;
		delete [] _data;
		_data = nullptr;
	}

	size_t size() const
	{	return _sz;	}

private:
	size_t _sz;
	char * _data;
};

int main()
{
	const char * str = "hello,world";
	CharArray ca(strlen(str) + 1);

	for(size_t idx = 0; idx != ca.size(); ++idx) {
		ca[idx] = str[idx];
	}

	for(size_t idx = 0; idx != ca.size(); ++idx) {
		cout << ca[idx] << "\n";	
	}
	return 0;
}
 
int test0(void)
{
	char * p = new char[10]();
	//.....
	//...
	
	delete [] p;
	p = nullptr;
	//.....
	//....
	*p = 's';//error
	

	return 0;
}
