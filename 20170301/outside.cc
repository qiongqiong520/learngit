///
/// @file    outside.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-03-02 19:30:13
///
//嵌套模板类的模板类
#include <iostream>
using namespace std;

template<class T>
class Outside//外部outside类
{
	public:
		template<class R>
			class Inside  //嵌套模板类
			{
	 			private:
					R r;
				public:
	 				Inside(R x)//模板类的成员函数可以在定义时实现
					{
						r=x;
					}
					//void disp()
					void disp()
					{
						cout<<"Inside:"<<r<<endl;
					}
			};
		//类模板不等于类定义，需要实例化或特化来生成类实例
		//inside类模板的高访问权限是public
		//Outside<int>::Inside<double>obin(3.5)
		//
		Outside(T x):t(x)//outside类的构造函数
		{}
		//void disp()
		void disp()
		{
			cout<<"Outside:";
			t.disp();
		}
	private:
		Inside<T> t;
};
#if 0
template<class T>
	template<class R>
void Outside<T>::Inside<R>::disp() //模板类的成员函数也可以在定义外实现
	//但必须时在所有类定义的外边，不能放在Outside内Inside外去实现
{
	cout<<"Inside:<<Outside<T>::Inside<R>::r"<<endl;
}
#endif
int main()
{
 	Outside<int>::Inside<double> obin(3.5);
	//声明Inside类对象obin
	obin.disp();

	Outside<int> obout(2);//创建Outside对象obout
	obout.disp();

	return 0;
}
