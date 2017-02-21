 ///
 /// @file    DebugAppenderexam.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 17:33:55
 ///
 
//win32DebugAppender是一个用于调试的appender，其功能是向winsows调试器写入日志
#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/Appender.hh>
#include<log4cpp/Win32DebugAppender.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/PatternLayout.hh>

using namespace std;
//queue变量时stringqueueappender被设计出来的记录多线程或实时程序的日志
int main(int argc,char* argv[])
{
	log4cpp::PatternLayout* pLayout1 =new
		log4cpp::PatternLayout();
	pLayout1->setConversionPattern("%d:%p %c %x : %m%n");

	log4cpp::Appender* debugAppender = new
		log4cpp::Win32DebugAppender("debugAppender");
	debugAppender->setLayout(pLayout1);


	log4cpp::Category& root =log4cpp::Category::getRoot();
	root.addAppender(debugAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("root error message!");
	root.warn("root warning message!");
	
	log4cpp::Category::shutdown();
	return 0;
}
