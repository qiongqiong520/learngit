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
	//对于static成员函数，要指定类名来调用
	//发生屏蔽现象，类成员可见域小于作用域，借助this指针，类名：：形式访问类成员
	public:
		static Singleton * getInstance(){//只有static成员函数能够:进行成员调用
			if(_pInstance ==NULL){
			_pInstance =new Singleton;
			}
			return new Singleton;
		}
		static void destory()
		{
			if(_pInstance)
				delete _pInstance;
		}
	private:
		Singleton(){}
		~Singleton(){}
	private:
		static Singleton * _pInstance;
};
//Singleton s3;
Singleton * Singleton::_pInstance = NULL;
int main(void){
	//Singleton s1;//不能编译通过
	//	Singleton s2;

	Singleton * ps1 =new Singleton::getInstance();
	Singleton * ps2 =new Singleton::getInstance();

	printf("ps1=%p\n",ps1);
	printf("ps2=%p\n",ps2);


return 0;
}

