 ///
 /// @file    templateconvert.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-28 20:57:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//嵌套模板函数的模板类
#if 0
template<typename T1,typename T2>
class Convert
{
	public:
		T2 execute(T1 date)//模板成员函数定义
		{
			return T1(data);//将b由t2类型强制转换成t1类型
		}
}
#endif
//在类外定义成员函数模板
template <typename T1>
class Convert
{
	public:
		template<typename T2>
			T2 execute(T1 data);
#if 0
		{
			return T2(data);
		}
#endif
};

//
template <typename T1>
template <typename T2>//模板类的成员函数也可以在定义外实现
T2 Convert<T1>::execute(T1 data)
{
	return T2(data);
}

int main(void)
{
	//Convert<char ,int>convert;
	//cout<<convert.execute('A')<<endl;
	
	Convert<char>convert;
	cout<< convert.execute<int>('A')<<endl;

	return 0;
}


