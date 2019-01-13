#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Complex
{
public:
	Complex operator+(const Complex& c1);
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
	
Complex Complex:: operator+(const Complex& c1)
{
	return Complex(_real + c1._real,_imag + c1._imag);
}
int main()
{
	Complex c1(1,3);
	Complex c2(2,5);
	Complex c3 = c1 + c2;
	Complex c4 = Complex(5) + c1;
	c4.print();
	return 0;
}

