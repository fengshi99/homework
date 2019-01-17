#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::string;
int main()
{
	ifstream is("xml.txt");
	string name;
	getline(is,name);
	cout << name << endl;
}
