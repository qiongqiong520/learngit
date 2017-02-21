 ///
 /// @file    LayoutExam.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 16:00:22
 ///
 
#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/PatternLayout.hh>

using namespace std;

int main(int argc,char* argv[])
{
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
	
	//PatternLayot使用setConversionPattern函数设置日志输出格式，该函数声明如下
	//void log4cpp::PatternLayout::SetConversionPattern(const std::string & conversionPattern)throw(configureFAilure)
	//%d日期%m消息%n换行符%p优先级%r自从layout被创建后的毫秒📖%R秒数
	//%u进程开始到目前为止的始终周期数
	//%x NDC消息，换行:x
	//
	log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
	pLayout->setConversionPattern("%d: %p %c %x: %m%n");
	osAppender->setLayout(pLayout);

	log4cpp::Category& root = log4cpp::Category::getRoot();
	log4cpp::Category& infoCategory = root.getInstance("infoCategory");
	infoCategory.addAppender(osAppender);

	infoCategory.info("system is running");
	infoCategory.warn("system is running");
	infoCategory.error("system has a error ,can't find a file");
	infoCategory.fatal("system has a warning");
	infoCategory.info("system shutdown ,you can find some information in the system log");

	log4cpp::Category::shutdown();

	return 0;
}
