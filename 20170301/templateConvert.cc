 ///
 /// @file    templateConvert.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-02 19:11:06
 ///
 
#include <iostream>

using namespace std;

//嵌套模板函数的模板类
//
template <class T1,class T2>
class Convert
{
	public:
		T2 f(T1 data)
		{
			return T2(data);
		}
};

//嵌套类模板函数的模板类

template<class T1>
//template<class T2>
class Test
{
	public:
		template<class T2>
			T1 f(T2 b)
			{
				return T1(b);
			}
};
#if 0
template<class T1>
//template<class T2>
T1 Test<T1>::f(T2 b)
{
	return T1(b);//将b由T2类型强制转换成T1类型
}
#endif

int main(void)
{
  	//普通模板类的使用
	Convert<char,int>c1;
	cout<<c1.f('A')<<endl;

	Convert<float,int>c2;
	cout<<c2.f(9.85f)<<endl;

	Convert<int,short> c3;
	cout<<hex<<showbase<<c3.f(0x7fffffff)<<endl<<dec;
	//通过上述3个例子，必须指明第一个模板参数
	

	//嵌套模板类的使用
	//
	Test<int> t;
	cout<<t.f(3.14f)<<endl;

	getchar();
	return 0;
}
