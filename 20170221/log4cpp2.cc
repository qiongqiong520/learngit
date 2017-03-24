 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 14:56:46
 ///
 
#include <iostream>

#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>

using std::cout;
using std::endl;

using namespace log4cpp;

int main(void)
{
 	log4cpp::OstreamAppender * osAppender=
		new log4cpp::OstreamAppender("osAppender ",&cout);

	log4cpp::PatternLayout * ptn1 = new log4cpp::PatternLayout();
	ptn1->setConversionPattern("%d :%p %c %x:%m %n");

	osAppender->setLayout(ptn1);

	log4cpp::Category &root=log4cpp::Category::getRoot();
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);
	root.error("Hello log4cpp in an error Msg!");
	root.warn("Hello log4cpp in an warn Msg!");

	log4cpp::Category::shutdown();

	return 0;
}
	
