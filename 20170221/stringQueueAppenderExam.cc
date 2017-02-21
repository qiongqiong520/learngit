///
/// @file    stringQueueAppenderExam.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-21 16:27:45
///


#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/StringQueueAppender.hh>
//
//使用啦两个队列容器
//std::queue 和std::string
using namespace std;

int main(int argc,char* argv[])
{
	log4cpp::StringQueueAppender* strQAppender = new
		log4cpp::StringQueueAppender("strQAppender");
	strQAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category& root = log4cpp::Category::getRoot();
	root.addAppender(strQAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a Warning Message!");
	
	//queue变量时stringqueueappender 类中用于具体存储日志的内存队列
	cout<<"Get message from Memory Queue!"<<endl;
	cout<<"-------------------------------------------"<<endl;
	queue<string>& myStrQ = strQAppender->getQueue();
	while(!myStrQ.empty())
	{
		cout<<myStrQ.front();
		myStrQ.pop();
	}
	

	//fieappender 和rollingFILEappender是log4cpp中常用的两个appender
	//功能是将日志写入文件
	//前者会一直在文件总记录日志，知道操作系统承受不了为止
	//后知会在文件长度达到指定长度时循环记录日志，文件长度不会超过指定
	log4cpp::Category::shutdown();    
	return 0;
}
