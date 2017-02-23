 ///
 /// @file    singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 10:08:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//1.不能是栈对象或全局对象
class Singleton
{
	public:
		static Singleton * getInstance(){//只有static成员函数能勾进行成员调用

			return new Singleton;
		}
	private:
		Singleton(){}
	private:
};
Singleton s3;

int main(void){
	//Singleton s1;//不能编译通过
	//	Singleton s2;

	Singleton * ps1 =new Singleton;
	Singleton * ps2 =new Singleton;
return 0;
}

