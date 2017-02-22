 ///
 /// @file    mylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 10:02:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Mylog{
	public:
		Mylog();

		~Mylog();
		void warn(const char* msg);
		void error(const char* msg);
		void debug(const char* msg);
		void info(const char* msg);
	private:

};
Mylog log;

//singleton
log.warn("hello");

int main(void)
{
	cout<<"hello world"<<endl;

	logInfo("Message");
	logError("Message");
	logWarn("Message");
	logDebug("Message");
}
