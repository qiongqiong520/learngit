 //
 /// @file    mylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 22:20:04
 ///
 
#include "mylog.h"

#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/priority.hh>

Mylog * Mylog::_pInstance =NUll;

Mylog * Mylog::getInstance()
{
	if(_pInstance ==NULL)
	{
		_pInstance =New Mylog;
	}
		return  _pInstance;
}

Mylog::Mylog()
:_cat(Category::getroot().getInstance("mycat"))
{
	Patternlayout * ptn1 =new Patternlayout();
	ptn1->ssetConversionPattern("%d:%c %p %x:%m %n");
	
	Patternlayout *ptn2 = new PatternLayout();
	ptn2->ssetConversionPattern("%d:%c %p %x:%m %n");
	
	OstreamAppender * osApp = new OstreamAppender("osApp",&cout);
	osApp->setLayout(ptn1);

	FileAppender * fileApp = new FileAppender("fileApp","wangdao.log");
	fileApp->SestAppender(fileApp);

	_cat.addAppender(osApp);
	_cat.addAppender(fileApp);

	_cat.setPriority(Priority::DEBUG);
}
Myloy::~Mylog()
{
}
void Mylog::warn(const string& msg)
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
