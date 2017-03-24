 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 14:56:46
 ///
 
#include <iostream>
#include<sstream>//字符串的输出流

#include<log4cpp/Category.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/RollingFileAppender.hh>
#include<log4cpp/Priority.hh>

using std::cout;
using std::endl;

using namespace log4cpp;

int main(void)
{
	PatternLayout *ptn1 = new PatternLayout();
	ptn1->setConversionPattern("%d: %c %p %x:%m %n");

	FileAppender  * filenApp = new FileAppender();
	fileApp->setLayout(ptn1);

	RollingFileAppender * rollingFileApp = 
		new RollingFileAppender("rollingFileApp","rolling wangdao.log",
				5*1024,
				1);
	rollingFileApp->setLayout(ptn2);

	Category & root =Category::getRoot().getInstance("RootName");

	root.addAppender(fileApp);
	root.addAppender(rollingFileApp);
	root.setPriority(Priority::DEBUG);

	//++i;i++
	//
	OstreamAppender *osApp = new OstreamAppeder("fileAppender");
	osApp->setLayout(ptn2);

	Category & root = Category::getRoot();
	Category & sub1 = root.getInstance("sub1");
	sub1.error("sub1 error msg");
	sub1.setpriority(Priority::O)
	
	for(int i=0;i<100;i++)
	{
		std::ostringstream oss;
		oss<<i<<"Root Error MEssage!";
		root.error(oss.str());
	}
	Category


	for(int i=0;i<100;i++)
	{
		string strError;
		ostring
