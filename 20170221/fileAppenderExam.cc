 ///
 /// @file    fileAppenderExam.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 17:04:19
 ///
 //实现循环写，产生两个log文件，旧的有82条记录，新的有18条文件记
#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/Appender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/RollingFileAppender.hh>

using namespace std;

int main(int argc,char* argv[])
{
	log4cpp::PatternLayout* pLayout1 = new log4cpp::PatternLayout;
	pLayout1->setConversionPattern("%d: %p %c %x:%m %n");

	log4cpp::PatternLayout* pLayout2 = new log4cpp::PatternLayout;
	pLayout2->setConversionPattern("%d:%p %c %x:%m%n");

	log4cpp::Appender* fileAppender = new
		log4cpp::FileAppender("fileAppender","wxb.log");
	fileAppender->setLayout(pLayout1);

	log4cpp::RollingFileAppender* rollfileAppender = new
		log4cpp::RollingFileAppender("rollfileAppender","rollwxb.log",5*1024,1);
	rollfileAppender->setLayout(pLayout2);
	
	//category种类
	log4cpp::Category& root = log4cpp::Category::getRoot().getInstance("RootName");
	root.addAppender(fileAppender);
	root.addAppender(rollfileAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	for(int i =0;i<100;i++)
	{
		string strError;
		ostringstream oss;
		oss<<i<<":Root Error Message!";
		strError =oss.str();
		root.error(strError);
	}

	log4cpp::Category::shutdown();
	return 0;
}
//程序运行会产生两个wxb.log和rollwxb.log文件，及一个备份文件
//记录所有100条日志记录,rollwxb.log
//大小为2kb，记录啦最新22一条记录
