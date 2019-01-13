#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	string filename = "heap_only.cc";
	ifstream input(filename,std::ios::in);
	string word;
	while(input>>word)
	{
		cout << word << endl;
	}
	input.close();
	return 0;
}
