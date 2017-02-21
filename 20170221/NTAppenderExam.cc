 ///
 /// @file    NTAppenderExam.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 20:21:12
 ///
 

//appender 可以讲日志发送到windows的日志，在运行程序后可以打开windows查看器，
//

#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/Appender.hh>
#include<log4cpp/NTEventLogAppender.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/PatternLayout.hh>

using namespace std;

int main(int argc ,char* argv[])
{
	log4cpp::PatternLayout* pLayout1=new
		log4cpp::PatternLayout();
	pLayout1->setConversionPattern("%d:%p %c %x:%m%n");

	log4cpp::Appender* ntAppender=new
		log4cpp::NTEventLogAppender("debugAppender","wxb_ntlog");
	ntAppender->setLayout(pLayout1);

	log4cpp::Category& root = log4cpp::Category::getRoot().getInstance("RootName");
	root.addAppender(ntAppender);
	root.setPriority(log4cpp::Priority::DEBUG);


	root.error("Root Error Message!");
	root.warn("Root Warning Message!");

	log4cpp::Category::shutdown();
	return 0;
}
