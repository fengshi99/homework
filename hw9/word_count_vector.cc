#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
class word_count
{
public:
	string _word;
	int _count;
	word_count(string word,int count)
		:_word(word)
		 ,_count(count)
	{}
};
class Dictionary
{
public:
	Dictionary() = default;
	~Dictionary() 
	{
		vector<word_count*>::iterator beg = _wc.begin();
		for(;beg!=_wc.end();++beg)
			delete (*beg);
	}		// cost 149.012 seconds
	void read(const string&);
	void store(const string&);
	void count(const string&);
private:
	vector<word_count*> _wc;
};
void Dictionary::read(const string& filename)
{
	ifstream input(filename,std::ios::in);
	string word;
	while(input >> word)
	{
		count(word);	
	}
}
void Dictionary::store(const string& filename)
{
	ofstream output(filename,std::ios::app);
	vector<word_count*>::iterator beg = _wc.begin();
	for(;beg!=_wc.end();++beg)
	{
		output << (*beg)->_word << ":" << (*beg)->_count << endl;
	/*	delete (*beg);*/  //cost 150.697 seconds
	}
}
void Dictionary::count(const string& word)
{
	vector<word_count*>::iterator beg = _wc.begin();
	int inserted = 1;
	for(;beg != _wc.end();++ beg)
	{
		if(word == (*beg)->_word)
		{
			++(*beg)->_count;
			inserted = 0;
		}
	}
	if(inserted)
	{
		_wc.push_back(new word_count(word,1));
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
	cout << "It cost " << (static_cast<double>(finish - start)/CLOCKS_PER_SEC) << "seconds" << endl;
	return 0;
}
