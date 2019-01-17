#include <iostream>
#include <limits>
#include <string.h>
#include <vector>
using std::cout;
using std::endl;
using std::cin;

class String
{
public:
	String() = default;
	String(const char* str)
		:_str(new char[strlen(str) + 1]())
		{
			strcpy(_str,str);
		}
	String(const String& str)
	{
		_str = new char[strlen(str._str) + 1]();
		strcpy(_str,str._str);
	}

	~String()
	{
		delete _str;
	}

	String& operator=(const String&);
	String& operator=(const char*);

	String& operator+=(const String&);
	String& operator+=(const char*);

	char& operator[](std::size_t);
	const char& operator[](std::size_t) const;

	std::size_t size() const;
	const char* c_str() const;

	friend bool operator==(const String&,const String&);
	friend bool operator!=(const String&,const String&);

	friend bool operator<(const String&,const String&);
	friend bool operator>(const String&,const String&);
	friend bool operator<=(const String&,const String&);
	friend bool operator>=(const String&,const String&);

	friend std::ostream& operator<<(std::ostream&,const String&);
	friend std::istream& operator>>(std::istream&,String&);



	void show()
	{
		cout << _str << endl;
	}
private:
	char* _str;
};
String& String::operator=(const String& str)
{
	_str = new char[strlen(str._str) + 1]();
	strcpy(_str,str._str);
}
String& String::operator=(const char* cstr)
{
	_str = new char[strlen(cstr) + 1]();
	strcpy(_str,cstr);
}
String& String::operator+=(const String& str)
{
	int t_len = strlen(_str);
	int s_len = strlen(str._str);

	char* temp = new char[t_len]();
	strcpy(temp,_str);
	delete _str;
	_str = new char[t_len + s_len +1]();
	
	for(int i =0;i <t_len;++i)
	{
		*(_str+i) = *(temp + i);
	}
	for(int i =t_len;i <t_len+s_len;++i)
	{
		*(_str+i) = *(str._str + (i - t_len));
	}
}
String& String::operator+=(const char* str)
{
	int t_len = strlen(_str);
	int s_len = strlen(str);

	char* temp = new char[t_len]();
	strcpy(temp,_str);
	delete _str;
	_str = new char[t_len + s_len +1]();
	
	for(int i =0;i <t_len;++i)
	{
		*(_str+i) = *(temp + i);
	}
	for(int i =t_len;i <t_len+s_len;++i)
	{
		*(_str+i) = *(str + (i - t_len));
	}
}
char& String:: operator[](std::size_t index)
{
	return *(_str + index);
}
const char& String::operator[](std::size_t index) const
{
	return *(_str + index);
}
std::size_t String::size()const
{
	return strlen(_str);
}
const char* String:: c_str() const
{
	return _str;
}
String operator+(const String& str1,const String& str2)
{
	String str3(str1.c_str());
	str3 += str2;
	return str3;
}
String operator+(const String& str1,const char* str2)
{
	String str3(str1.c_str());
	str3 += str2;
	return str3;
}
String operator+(const char* str1,const String& str2)
{
	String str3(str1);
	str3 += str2;
	return str3;
}
bool operator==(const String& str1,const String& str2)
{
	if(str1.size() == str2.size())
	{
		int flag = str1.size() -1;
		while(flag != -1)
		{
			if(str1[flag] != str2[flag--])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}
bool operator!=(const String& str1,const String& str2)
{
	if(str1 == str2)
		return false;
	return true;
}
bool operator<(const String& str1,const String& str2)
{
	if(str1 != str2)
	{
		if(str1.size() < str2.size())
		{
			return true;
		}
		else if(str1.size() == str2.size())
		{
			int flag =0;
			int size = str1.size();
			while(flag < size)
			{
				if(str1[flag] == str2[flag])
					++flag;
				else if(str1[flag] < str2[flag])
					return true;
				else
					return false;
			}
		}
	}
	return false;
}
bool operator>(const String& str1,const String& str2)
{
	if(str1 != str2 && !(str1 < str2))
		return true;
	return false;
}
bool operator>=(const String& str1,const String& str2)
{
	if(str1.size() != str2.size())
	{
		int flag =0;
		int size = str1.size() > str2.size()?str2.size() : str1.size() ;
		while(flag < size)
		{
			if(str1[flag] != str2[flag++])
				return false;
		}
		if(str1.size() > str2.size())
			return true;
	}
	return false;
}
bool operator<=(const String& str1,const String& str2)
{
	if(str1.size() != str2.size())
	{
		int flag =0;
		int size = str1.size() > str2.size()?str2.size() : str1.size() ;
		while(flag < size)
		{
			if(str1[flag] != str2[flag++])
				return false;
		}
		if(str1.size() < str2.size())
			return true;
	}
	return false;
}
std::ostream& operator<<(std::ostream& os,const String& str)
{
	os << str.c_str();
	return os;
}
std::istream& operator>>(std::istream& is,String &str)
{
	std::vector<char> cvec;
	char c;
	while(is >> c , !is.eof())
	{
		if(is.bad())
		{
			cout << "istream is out of running!" << endl;
		}
		else if(is.fail())
		{
			cout << "please input valid variables" << endl;
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		if(c == '@')
			break;
		cvec.push_back(c);
	}
	str._str = new char[cvec.size()]();
	int i =0;
	for(auto& c:cvec)
	{
		*(str._str + (i++)) = c;
	}
	return is;
}
int main()
{
	String s1("String One");
	String s2("String Two");
	char a[] = "Char";
	cout << "Now testing :cout << s1 << endl" << endl;
	cout << s1 << endl;
	cout << "Now testing :cout << s2 << endl" << endl;
	cout << s2 << endl;
	cout << "-------------------------------" << endl;
	cout << "Now testing :s1 + s2 = "
						<< s1 + s2 << endl;
	cout << "a:Char" << endl;
	cout << "Now testing :s1 + a = "
						<< s1 + a << endl;
	cout << "-------------------------------" << endl;
	cout << "Now testing :s1 = s2" << endl;
	s1 = s2;
	cout << "s1 = " << s1 << endl;
	cout << "Now testing operator==: s1==s2? "; 
	if (s1 == s2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cout << "-------------------------------" << endl;
	s1 = "String";
	s2 = "String";
	cout << "s1:" << s1 << "   s2:" << s2 << endl;
	cout << "s1 != s2? ";
	if (s1 != s2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cout << "-------------------------------" << endl;

	s1 = "Strin";
	s2 = "String";
	cout << "s1:" << s1 << "   s2:" << s2 << endl;
	cout << "s1 < s2? ";
	if (s1 < s2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cout << "-------------------------------" << endl;
	s1 = "String";
	s2 = "StrinG";
	cout << "s1:" << s1 << "   s2:" << s2 << endl;
	cout << "s1 < s2? ";
	if (s1 < s2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	cout << "-------------------------------" << endl;
	s1 = "StrinG";
	s2 = "String";
	cout << "s1:" << s1 << "   s2:" << s2 << endl;
	cout << "s1 < s2? ";
	if (s1 < s2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cout << "-------------------------------" << endl;
	s1 = "Strin";
	s2 = "String";
	cout << "s1:" << s1 << "   s2:" << s2 << endl;
	cout << "s1 <= s2? ";
	if (s1 <= s2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cout << "-------------------------------" << endl;
	s1 = "String1";
	s2 = "String";
	cout << "s1:" << s1 << "   s2:" << s2 << endl;
	cout << "s1 >= s2? ";
	if (s1 >= s2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cout << "-------------------------------" << endl;
	s1 = "Hello";
	s2 = "String";
	cout << "s1:" << s1 << "   s2:" << s2 << endl;
	cout << "s1[3]:"<<s1[3] << "     s2[3]" << s2[3] << endl;
	cout << "-------------------------------" << endl;
	cout << "pleasr input a string for s2,end with '@'" << endl;
	cin >> s2;
	cout << "s2:" << s2 << endl;

	return 0;
}
