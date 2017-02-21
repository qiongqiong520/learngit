///
/// @file    helloLog4cpp.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-21 14:53:03
///


#include<iostream>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/Category.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/priority.hh>
using namespace std;

int main(int argc,char* argv[])
{
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
	osAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category& root = log4cpp::Category::getRoot();
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a Warning Message!");

	log4cpp::Category::shutdown();    
	return 0;
}
