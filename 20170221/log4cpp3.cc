 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 14:56:46
 ///
 
#include <iostream>
#include<sstream>

#include<log4cpp/Category.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/RollingFileAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>

using std::cout;
using std::endl;

using namespace log4cpp;

int main(void)
{
	PatternLayout *ptn1=new PatternLayout();
	ptn1->setConversionPattern("%d :%c %p %x:%m%n");

	PatternLayout *ptn2=new PatternLayout();
	ptn2->setConversionPattern("%d :%c %p %x:%m%n");
 
	FileAppender *fileApp=new FileAppender("fileApp","wangdao.log");
	fileApp->setLayout(ptn1);

	RollingFileAppender * rollingFileApp =
		new RollingFileAppender("rollingFileApp","rollingwangdao.log",
				5*1024,1);
	rollingFileApp->setLayout(ptn2);

	Category & root =Category::getRoot().getInstance("RootName");
	root.addAppender(fileApp);
	root.addAppender(rollingFileApp);
	root.setPriority(Priority::DEBUG);

	for(int i=0;i!=100;++i)
	{
		std::ostringstream oss;
		oss<<i<<":Root Error Message!";
		root.error(oss.str());
	}
	Category::shutdown();

	return 0;
}

	
