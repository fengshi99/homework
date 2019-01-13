#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
using std::cout;
using std::endl;
using std::cin;
void test1()
{
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osappender",&cout);
	osAppender -> setLayout(new log4cpp::BasicLayout());
	log4cpp::Category& root = log4cpp::Category::getRoot();
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);
	root.error("This is log4cpp error message");
	root.warn("This is log4cpp warn message");
	log4cpp::Category::shutdown();
}
void test2()
{
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
	log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
	pLayout -> setConversionPattern("%d %p %c %x %m%n");/*%d-> date,%p->priority,%c->category,
																 %x->NDC,%m->message,%n-><cr> */
	osAppender->setLayout(pLayout);
	
	log4cpp::Category& root = log4cpp::Category::getRoot();
	log4cpp::Category& infoCategory = root.getInstance("infoCategory");
	infoCategory.addAppender(osAppender);
	infoCategory.setPriority(log4cpp::Priority::INFO);

	infoCategory.info(" This is log4cpp info message");
	infoCategory.warn("This is log4cpp warn message");
	infoCategory.error("This is log4cpp error message");
	infoCategory.fatal("This is log4cpp fatal message");
	log4cpp::Category::shutdown();
}
void test3()
{
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
	log4cpp::RollingFileAppender* RFAppender = 
		new log4cpp::RollingFileAppender("RFAppender","RFAfile.log",10*1024,3);
	log4cpp::PatternLayout* pLayout1 = new log4cpp::PatternLayout();
	pLayout1->setConversionPattern("%d %p %c %x %m%n");
	log4cpp::PatternLayout* pLayout2 = new log4cpp::PatternLayout();
	pLayout2->setConversionPattern("%d %p %c %x %m%n");
	osAppender->setLayout(pLayout1);
	RFAppender->setLayout(pLayout2); // one appender,one layout
	/*
	log4cpp::Category& root = log4cpp::Category::getRoot();
	log4cpp::Category& infoCategory = root.getInstance("infoCategory");
	infoCategory.addAppender(osAppender);
	infoCategory.addAppender(RFAppender);
	*/
	log4cpp::Category& root = log4cpp::Category::getRoot().getInstance("ROOTNAME");
	root.addAppender(osAppender);
	root.addAppender(RFAppender);

	root.setPriority(log4cpp::Priority::INFO);
	

	for(int idx = 0;idx < 10;++idx)
	{
	root.info("This is log4cpp info message");
	root.warn("This is log4cpp warn message");
	root.error("This is log4cpp error message");
	root.fatal("This is log4cpp fatal message");
	}
	root.error("now out of for");
	log4cpp::Category::shutdown();
	cout << "already shut down" << endl;
}
int main()
{
	test3();
	return 0;
}
