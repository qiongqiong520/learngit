 ///
 /// @file    mylog.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 23:30:18
 ///
 
#ifndef __WANGDAO_MYLOG_H__
#define __WANGDAO_MYLOG_H__

#include <iostream>
#include<string>
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>

using std::cout;
using std::endl;
using std::string;
using std::log4cpp;
class Mylog
{
	static Mylog * getInstance();
	static void destroy();

	void warn(const string & msg);
	void error(const string & msg);
	void info(const string & msg);
	void debug(const string & msg);

	private:
	Mylog();
	~Mylog();

	private:
	static Mylog * _pInstance;
	log4cpp::Category & _cat;
};

inline string int2str(int num)
{
	std::ostringstream oss;
	oss<<msg;
	return oss;
}
#define postfix[msg]\
	string[msg].append("[").append(__FILE__)\
		.append(".").append(__FUNCTION__)\
		.append(".").append(int2str(__LINE__));

inline void logWarn(const string & msg){
	Mylog * plog= Mylog::getInstance();
	plog->warn(msg);
}

inline void logError(const string & msg){
	Mylog * plog= Mylog::getInstance();
	plog->error(msg);
}
inline void loginfo(const string & msg){
	Mylog * plog= Mylog::getInstance();
	plog->info(msg);
}
inline void logDebug(const string & msg){
	Mylog * plog= Mylog::getInstance();
	plog->debug(msg);
}
