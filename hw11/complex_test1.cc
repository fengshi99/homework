#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Complex
{
public:
	friend Complex operator+(const Complex &c1,const Complex &c2);
	Complex(int real =0,int imag =0)
		:_real(real)
		 ,_imag(imag){}
	~Complex() = default;
	void print();
private:
	int _real;
	int _imag;
};
void Complex::print()
{
	cout << _real << "+" << _imag << "*i" << endl;
}
	
Complex operator+(const Complex& c1,const Complex& c2)
{
	return Complex(c1._real + c2._real,c1._imag + c2._imag);
}
int main()
{
	Complex c1(1,3);
	Complex c2(2,5);
	Complex c3 = c1 + 5;
	c3 = c2 +5;
	c3.print();
	return 0;
}

