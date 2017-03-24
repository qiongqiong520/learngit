 //
 /// @file    mylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 22:20:04
 ///
 
#include "mylog.h"

#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>

Mylog * Mylog::_pInstance =NULL;

Mylog * Mylog::getInstance()
{
	if(_pInstance ==NULL)
	{
		_pInstance =new Mylog;
	}
		return  _pInstance;
}

Mylog::Mylog()
:_cat(log4cpp::Category::getRoot().getInstance("mycat"))
{
	log4cpp::PatternLayout * ptn1 =new log4cpp::PatternLayout();
	ptn1->setConversionPattern("%d:%c %p %x:%m %n");
	
	log4cpp::Patternlayout *ptn2 = new log4cpp::PatternLayout();
	ptn2->setConversionPattern("%d:%c %p %x:%m %n");
	
	log4cpp::OstreamAppender * osApp = new log4cpp::OstreamAppender("osApp",&cout);
	osApp->setLayout(ptn1);

	log4cpp::FileAppender * fileApp = new log4cpp::FileAppender("fileApp","wangdao.log");
	fileApp->setLayout(fileApp);

	_cat.addAppender(osApp);
	_cat.addAppender(fileApp);

	_cat.setPriority(log4cpp::Priority::DEBUG);
}
Myloy::~Mylog()
{
}
void Mylog::warn(const std::string& msg)
{
	_cat.warn(msg.c_str());
}

void Mylog::error(const string & msg)
{
	_cat.error(msg.c_str());
}

void Mylog::info(const string & msg)
{
	_cat.info(msg.c_str());
}

void Mylog::debug(const string & msg)
{
	_cat.debug(msg.c_str());
}
