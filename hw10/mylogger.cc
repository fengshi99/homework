#include <iostream>
#include <fstream>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::ofstream;
using std::time_t;
class MyLogger
{
public:
	static MyLogger* GetInstance();
	static void destory();
	void SetOstream(ostream*);
	void SetOfstream(ofstream*);
	void warn(const char*);
	void error(const char*);
	void debug(const char*);
	void info(const char*);
private:
	static MyLogger* _mylogger;
	ostream* _output;
	ofstream* _foutput;
	int os_settled;
	int fs_settled;
	MyLogger()
		:os_settled(0)
		 ,fs_settled(0)
		{}
	~MyLogger() = default;	
};
MyLogger* MyLogger::_mylogger = nullptr;
void MyLogger::SetOstream(ostream* output)
{
	_output = output;
	os_settled = 1;
}
void MyLogger::SetOfstream(ofstream* foutput)
{
	_foutput = foutput;
	fs_settled = 1;
}
MyLogger* MyLogger::GetInstance()
{
	if(nullptr == _mylogger)
	{
		return new MyLogger();
	}
	else
		return _mylogger;
}
void MyLogger::destory()
{
	delete _mylogger;
}
void MyLogger::warn(const char* msg)
{
	time_t result = std::time(nullptr);
	if(msg)
	{	
		if(os_settled)
			(*_output) << std::asctime(std::localtime(&result)) 
				<< "Line:" << __LINE__
				<< " File:" << __FILE__ 
				<< " Funciton:" << __FUNCTION__ 
				<< " WARN " << msg << endl;
		if(fs_settled)
			(*_foutput) << std::asctime(std::localtime(&result)) 
				<< "Line:" << __LINE__
				<< " File:" << __FILE__ 
				<< " Funciton:" << __FUNCTION__ 
				<< " WARN " << msg << endl;
	}
}
void MyLogger::error(const char* msg)
{
	
	time_t result = std::time(nullptr);
	if(msg)
	{	
		if(os_settled)
			(*_output) << std::asctime(std::localtime(&result)) 
				<< "Line:" << __LINE__
				<< " File:" << __FILE__ 
				<< " Funciton:" << __FUNCTION__ 
				<< " ERROR " << msg << endl;

		if(fs_settled)
			(*_foutput) << std::asctime(std::localtime(&result)) 
				<< "Line:" << __LINE__
				<< " File:" << __FILE__ 
				<< " Funciton:" << __FUNCTION__ 
				<< " ERROR " << msg << endl;
	}
}
void MyLogger::debug(const char* msg)
{
		
	time_t result = std::time(nullptr);
	if(msg)
	{	
		if(os_settled)
			(*_output) << std::asctime(std::localtime(&result)) 
				<< "Line:" << __LINE__
				<< " File:" << __FILE__ 
				<< " Funciton:" << __FUNCTION__ 
				<< " DEBUG " << msg << endl;
		if(fs_settled)
			(*_foutput) << std::asctime(std::localtime(&result)) 
				<< "Line:" << __LINE__
				<< " File:" << __FILE__ 
				<< " Funciton:" << __FUNCTION__ 
				<< " DEBUG " << msg << endl;

	}
}
void MyLogger::info(const char* msg)
{
		
	time_t result = std::time(nullptr);
	if(msg)
	{	
		if(os_settled)
			(*_output) << std::asctime(std::localtime(&result)) 
				<< "Line:" << __LINE__
				<< " File:" << __FILE__ 
				<< " Funciton:" << __FUNCTION__ 
				<< " INFO " << msg << endl;
		if(fs_settled)
			(*_foutput) << std::asctime(std::localtime(&result)) 
				<< "Line:" << __LINE__
				<< " File:" << __FILE__ 
				<< " Funciton:" << __FUNCTION__ 
				<< " INFO " << msg << endl;
	}
}
int main()
{
	MyLogger* mylogger = MyLogger::GetInstance();
	mylogger -> SetOstream(&cout);
	ofstream output("mylog.log");
	mylogger -> SetOfstream(&output);
	mylogger -> info("This is info");
	mylogger -> error("This is error");
	mylogger -> debug("This is debug");
	mylogger -> warn("This is warn");
	MyLogger::destory();
	return 0;
}
