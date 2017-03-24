 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 14:56:46
 ///
 
#include <iostream>

#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/Priority.hh>

using std::cout;
using std::endl;

using namespace log4cpp;

int main(void)
{
	log4cpp::OstreamAppender * osAppender=
		new log4cpp::OstreamAppender("osAppender ",&cout);

	osAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root =log4cpp::Category::getRoot();
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::ERROR);

	root.error("Hello log4cpp in an error Msg");
	root.warn("Hello log4cpp in a warn Msg");
	log4cpp::Category::shutdown();

	return 0;
}
