 ///
 /// @file    parentheses.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-01-14 16:24:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//重载了函数调用运算符的类创建的对象的称为函数对象
//
//一般称携带了状态的函数对象为 闭包 => 匿名函数 => lambda表达式
//
class FunctionObject
{
public:
	FunctionObject()
	: _count(0)
	{}

	//() 函数调用运算符
	int operator()(int x, int y) 
	{
		cout << "operator()(int,int) " << endl;
		++_count;
		return x + y;
	}

	int operator()(int x, int y, int z) 
	{
		cout << "operator()(int,int,int) " << endl;
		++_count;
		return x * y * z;	
	}

private:
	int _count;//函数对象的状态
};

//python
int func(int x, int y)
{	//没有携带状态
	static int count = 0;//局部静态变量  ==> 全局/静态区
	++count;
	return x + y;
}

//typedef int(*Function)(int,int);
//Function f = func;
//f(a,b);


 
int main(void)
{
	int a = 3, b = 4, c = 5;
	FunctionObject fo;//本身是一个对象
	cout << "fo(a, b) = " << fo(a, b) << endl;//在形式上是一个函数的写法
	cout << "fo(a, b, c) = " << fo(a, b, c) << endl;
	cout << "func(a, b) = " << func(a, b) << endl;

	FunctionObject fo2;

	return 0;
}
