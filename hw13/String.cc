#include <iostream>
#include <stdio.h>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;
class String
{
public:
	String()
		:_pstr(new char[4 + 1] + 4){}
	String(const char* pstr)
		:_pstr(new char[4 + 1 + strlen(pstr)] + 4)
	{
		init_ref();
		strcpy(_pstr,pstr);
	}
	~String()
	{
		release_ref();
	}
	String(const String& str)
	{
		_pstr = str._pstr;
		increase_ref();
	}
	String& operator=(const String& str)
	{
		if(_pstr != str._pstr)
		{
			decrease_ref();
			if(ref() == 0)
			{
				release_ref();
			}
			_pstr = str._pstr;
			increase_ref();
		}
		return (*this);
	}
	const char* c_str() const;
	int size() const;
	class Char
	{
		friend std::ostream& operator<<(std::ostream& os,const String::Char& ch); 
		public:
			Char(String& str,size_t idx)
				:_self(str)
				 ,_idx(idx){}
			char& operator=(const char ch);
		private:
			String& _self;
			size_t _idx;
	};

	 Char operator[](size_t index)
	{
		return Char(*this,index);
	}
	/*-----------------------------------------*/
	/*-----------------------------------------*/


	friend std::ostream& operator<<(std::ostream& os,const String::Char& ch); 
	friend std::ostream& operator<<(std::ostream& os,const String& str);
private:
	int ref();
	void init_ref();
	void decrease_ref();
	void increase_ref();
	void release_ref();
	char* _pstr;
};
std::ostream& operator<<(std::ostream& os,const String::Char& ch)
{
	os << ch._self._pstr[ch._idx];
	return os;
}
char& String::Char::operator=(const char ch)
{
	if(_idx < _self.size())
	{
		if(_self.ref() > 1)
		{
			char* temp = new char[_self.size() + 5]() + 4;
			strcpy(temp,_self._pstr);
			_self.decrease_ref();
			_self._pstr = temp;
			_self.init_ref();
		}
		_self._pstr[_idx] = ch;
		return _self._pstr[_idx];
	}
	static char c = '\0';
	return c;
}

int String::size() const
{
	return strlen(_pstr);
}
const char* String::c_str() const
{
	return _pstr;
}
int String::ref()
{
	return *(int*)(_pstr - 4);
}
void String::init_ref()
{
	*(int*)(_pstr - 4) = 1;
}
void String::decrease_ref()
{
	--*(int*)(_pstr - 4);
}
void String::increase_ref()
{
	++*(int*)(_pstr - 4);
}
void String::release_ref()
{
	decrease_ref();
	if(ref() == 0)
	{
		delete [](_pstr - 4);
	}
}
std::ostream& operator<<(std::ostream& os,const String& str)
{
	os << str.c_str();
	return os;
}
int main()
{
	String s1("hello");
	String s2 = s1;
	printf("s1: %p\n",s1.c_str());
	printf("s2: %p\n",s2.c_str());
	String s3 = s1;
	cout << s3 << endl;
	cout << "s3[2]: "<< s3[2] << endl;
	printf("s3: %p\n",s3.c_str());
	cout << "------------" << endl;
	s3[2] = 'R';
	cout << s3 << endl;
	printf("s3: %p\n",s3.c_str());
	return 0;
}
