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
inline string format(const string& text);
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
	XMLElement* channel = root->FirstChildElement("channel");
	XMLElement* item = nullptr; 
	if(channel)
	{
		item = channel->FirstChildElement("item");
		if(!item)
			return;
	}
	cout << "Loading " << filename << endl;
	while(item)
	{
		if(item->FirstChildElement("title"))
		{	
			if(item->FirstChildElement("title")->GetText())
				RI.Title =format(static_cast<string>(item->FirstChildElement("title")->GetText()));
		}
		else
			RI.Title = "NULL";
		if(item->FirstChildElement("link"))
		{
			if(item->FirstChildElement("link")->GetText())
				RI.Link = format(static_cast<string>(item->FirstChildElement("link")->GetText()));	
		}
		else
			RI.Title = "NULL";
		if(item->FirstChildElement("description"))
		{
			if(item->FirstChildElement("description")->GetText())
				RI.Description = format(static_cast<string>(item->FirstChildElement("description")->GetText()));
		}
		else
			RI.Title = "NULL";
		if(item->FirstChildElement("content:encoded"))
		{
			if(item->FirstChildElement("content:encoded")->GetText())
				RI.Content = format(static_cast<string>(item->FirstChildElement("content:encoded")->GetText()));
		}
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
	os.close();
}
string format(const string& text)
{
	string temp = text;
	regex r("<.*?>");
	temp = regex_replace(text,r," ");
	r = string("&nbsp;");
	temp = regex_replace(temp,r," ");
	return temp;
}
int main()
{	
	system("find -name \"*.xml\" > xml.txt");
	ifstream is("xml.txt");
	string filename;
	while(getline(is,filename))
	{	
		RssReader rss;
		rss.parseRss(filename.c_str());
		rss.dump(string("pagelib.txt"));
	}
	cout << "finished!" << endl;
	return 0;
}
