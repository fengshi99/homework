#include <iostream>
#include "tinyxml2.h"
#include <regex>
#include <string>
#include <stdio.h>
#include <vector>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::regex;
using namespace tinyxml2;
inline string format(string text);
struct RssItem
{
	string Title;
	string Link;
	string Description;
	string Content;
};
class RssReader
{
public:
	RssReader() = default;
	~RssReader() = default;
	void parseRss(const char*);
	void dump(const string&);
private:
	vector<RssItem> _rss;
};
void RssReader::parseRss(const char* filename)
{
	RssItem RI;
	XMLDocument* doc = new XMLDocument();
	doc->LoadFile(filename);
	XMLElement* root = doc -> RootElement();
	XMLElement* channel = doc->FirstChildElement("channel");
	cout << "channel get" << endl;
	XMLElement* item = channel->FirstChildElement("item");
	cout << "Loading " << filename << endl;
	while(item)
	{
		if(item->FirstChildElement("title"))
			RI.Title =format(static_cast<string>(item->FirstChildElement("title")->GetText()));
		else
			RI.Title = "NULL";
		if(item->FirstChildElement("link"))
			RI.Link = format(static_cast<string>(item->FirstChildElement("link")->GetText()));	
		else
			RI.Title = "NULL";
		if(item->FirstChildElement("description"))
			RI.Description = format(static_cast<string>(item->FirstChildElement("description")->GetText()));
		else
			RI.Title = "NULL";
		if(item->FirstChildElement("content:encoded"))
			RI.Content = format(static_cast<string>(item->FirstChildElement("content:encoded")->GetText()));
		else
			RI.Title = "NULL";
		_rss.push_back(RI);
		item = item->NextSiblingElement();
	}
	delete doc;
}
void RssReader::dump(const string& filename)
{
	ofstream os(filename,std::ios::app);
	static int id =0;
	for(auto& c:_rss)
	{
		os << "<doc>" << endl;
		os << "<docid>" << ++id << "</docid>" << endl;
		os << "<title>" << c.Title << "</title>" << endl;
		os << "<link>" << c.Link << "</link>" << endl;
		os << "<description>" << c.Description << "<description>" << endl;
		os << "<content>" << c.Content << "</content>" << endl;
		os << "</doc>" << endl;
	}
}
string format(string text)
{
	string temp = text;
	regex r("<.*?>");
	temp = regex_replace(text,r," ");
	r = string("&nbsp;");
	temp = regex_replace(temp,r," ");
//	r = string("\n");
//	temp = regex_replace(temp,r,"");
	return temp;
}
int main()
{	
		RssReader rss;
		rss.parseRss("./resources/techweb.xml");
		rss.dump(string("pagelib.txt"));
	cout << "finished!" << endl;
	return 0;
}
