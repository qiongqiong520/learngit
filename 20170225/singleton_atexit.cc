 ///
 /// @file    singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 10:08:13
 ///
#include<stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
//1.不能是栈对象或全局对象
//2.单例对象自动回收,栈对象
//只有载该对象的啊析构函数里面去执行destory函数的
//2.通过内部类+静态对象  解决类单例对象自动解释问题
class Singleton
{
	//对于static成员函数，要指定类名来调用
	//发生屏蔽现象，类成员可见域小于作用域，借助this指针，类名：：形式访问类成员
	public:
		static void destory()
		{

		}
	private:
		class AutoRelease
		{
			public:
				AutoRelease()
				{
					}
				~AutoRelease()//_ix内部类不能直接访问外围类的静态成员
				{}
			void print()
			{}
		}
	private:
		static Singleton * _pInstance;
		static AutoRelease _ar;//_ar不能是非static的
};
Singleton * Singleton::_pInstance = NULL;
Singleton::AutoRelease Singleton::_ar;
int main(void){
	Singleton::Auto
	return 0;
}

