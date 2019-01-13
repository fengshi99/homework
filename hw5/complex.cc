#include <iostream>
using namespace std;

class complex
{
private:
	double real;
	double imag;
public:
	complex()
	{
		real = 0.0;
		imag = 0.0;
	}
	complex(double ireal,double iimag):real(ireal),imag(iimag){}
	complex(const complex &C)
	{
		real = C.real;
		imag = C.imag;
	}
	~complex(){}
	complex operator+(const complex&);
	complex operator-(const complex&);
	complex operator*(const complex&);
	complex operator/(const complex&);
	complex& operator++();
	complex operator++(int);
	complex operator+=(const complex&);
	complex operator-=(const complex&);
	void show()
	{
		cout << real << "+i*" << imag <<endl;
	}
};
complex complex::operator+(const complex &C)
{
	return complex(real + C.real,imag + C.imag);
}
complex complex::operator-(const complex &C)
{
	return complex(real - C.real,imag - C.imag);
}
complex complex::operator*(const complex &C)
{
	return complex(real*C.real-imag*C.imag,real*C.imag+imag*C.real);
}
complex complex::operator/(const complex &C)
{
	double bottom = (C.real*C.real) + (C.imag*C.imag);
	complex Ctemp = (*this)*complex(C.real,-C.imag);
	return complex(Ctemp.real/bottom,Ctemp.imag/bottom);
}
complex& complex::operator++()		//ahead
{
	++real;
	++imag;
	return (*this);
}
complex complex::operator++(int)	//behind
{
	complex Ctemp = (*this);
	++(*this);
	return Ctemp;
}
complex complex::operator+=(const complex &C)
{
	real+=C.real;
	imag+=C.imag;
	return (*this);
}
complex complex::operator-=(const complex &C)
{
	real-=C.real;
	imag-=C.imag;
	return (*this);
}

int main()
{
	complex c1(3.0,2.0);
	cout << "c1 is ";c1.show();
	complex c2(5.0,6.0);
	cout << "c2 is ";c2.show();
	complex c3 = c1+ c2;
	cout << "c3 = c1+c2,now c3 is"; c3.show(); 
	c3 = c1*c2;
	cout << "c3 = c1*c2,now c3 is"; c3.show();
	c3 = c1-c2;
	cout << "c3 = c1-c2,now c3 is"; c3.show();
	c3 = c1/c2;
	cout << "c3 = c1/c2,now c3 is"; c3.show();
	++c1;
	cout << "++c1,now c1 is ";c1.show();
	c3 = c2++;
	cout << "I tried c3 = c2++,now c2 is ";c2.show();
		cout << "but c3 is ";c3.show();
	c3+=c1;
	cout << "c3 += c1,now c3 is";c3.show();
	c3-=c1;
	cout << "c3 -= c1,now c3 is";c3.show();
	return 0;

}
