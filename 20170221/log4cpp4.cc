 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 14:56:46
 ///
 
#include <iostream>
#include<sstream>

#include<log4cpp/Category.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/OstreamAppender.hh>
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


	OstreamAppender * osApp =new OstreamAppender("osApp",&cout);
	osApp->setLayout(ptn2);

	Category & root =Category::getRoot();//定义子类对象
	Category & sub1 =root.getInstance("sub1");//调用子类对象的方法
	sub1.setAppender(osApp);
	sub1.setPriority(Priority::DEBUG);

	sub1.error("sub1 error msg!");

	Category & sub2=root.getInstance("sub2");
	sub2.setAppender(fileApp);
	sub2.setPriority(101);

	sub2.warn("sub2 warning msg");
	sub2.fatal("sub2 fatal msg");
	sub2.alert("sub2 alert msg");
	sub2.crit("sub2 crit msg");

	Category::shutdown();

	return 0;
}


