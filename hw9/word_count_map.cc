#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <time.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
using std::map;
class Dictionary
{
public:
	Dictionary() = default;
	~Dictionary() = default;
	void read(const string&);
	void store(const string&);
private:
	map<string,size_t> word_count;
};
void Dictionary::read(const string& filename)
{
	ifstream input(filename,std::ios::in);
	string word;
	while(input >> word)
	{
		++word_count[word];
	}
}
void Dictionary::store(const string& filename)
{
	ofstream output(filename,std::ios::app);
	for(const auto &w: word_count)
	{
		output << w.first << ":" << w.second << endl;
	}
}
int main()
{
	clock_t start,finish;
	start = clock();
	Dictionary dict;
	dict.read("The_Holy_Bible.txt");
	dict.store("dictionary.txt");
	finish = clock();
	cout << "It cost" << (static_cast<double>(finish - start)/CLOCKS_PER_SEC) << "seconds" << endl;
	return 0;
}	//It cost 0.570906 seconds
