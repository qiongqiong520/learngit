 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-06 22:42:40
 ///
#include<stdio.h>
#include <iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

class String{
	public:
		String()
			:_pstr(new char[1])
		{}
		String(const char * pstr)
			:_pstr(new char[strlen(pstr)+1])
		{
			cout<<"String(const char*)"<<endl;
			strcpy(_pstr,pstr);
		}
	//const&的语法无法识别出传递过来的对象
	//是否是临时对象
	//对于const&而言，他可以接受任意的对象
	//
	//复制构造函数
	String(const String &rhs)
		:_pstr(new char[strlen(rhs._pstr)+1])
	{
		cout<<"String(const String &)"<<endl;
		strcpy(_pstr,rhs._pstr);
	}
	//注意：当复制构造函数和移动构造函数同时存在时
	//如果传递过来的右值
	//移动构造函数会被优先调用，是不会产生二义性的
	String(String && rhs)
		:_pstr(rhs._pstr)//浅拷贝
	{
		cout<<"String (string &&)"<<endl;
		rhs._pstr=NULL;//这一步不可少，同时说明右值饮用的诞生就意味着修改
	}

	//移动赋值运算符函数
	String & operator =(String &rhs)
	{
 		cout<<"String & operator=(String & rhs)"<<endl;
		delete []_pstr;
		_pstr =rhs._pstr;//浅拷贝
		rhs._pstr = NULL;
			return *this;
	}
//赋值运算符函数
	String & operator=(const String & rhs)
	{
		cout<<"String & operator =(const String&)"<<endl;
		if(this!=&rhs)
		{
		delete []_pstr;
		_pstr=new char[strlen(rhs._pstr)+1];//假如new操作失败
		strcpy(_pstr,rhs._pstr);
		}
		return *this;
	}
	~String()
	{
		cout<<"~String()"<<endl;
		delete []_pstr;
	}

	String & operator+=(const String & rhs)
	{
		char * ptmp = new char[strlen(_pstr)+strlen(rhs._pstr)+1];
		strcpy(_pstr,rhs._pstr);
		strcat(ptmp,rhs._pstr);
		delete []_pstr;
		_pstr =ptmp;
		return *this;
	}

	friend std::ostream & operator<<(std::ostream &os,const String &rhs);

	private:
		char* _pstr;
};

std::ostream & operator<<(std::ostream &os,const String & rhs)
{
 	os<<rhs._pstr;
	return os;
}
String operator+(const String &lhs,const String &rhs)
{
 	String tmp(lhs);//初始化并赋值为lhs
	tmp+=rhs;
	return tmp;
} 
#if 0
int main(void)
{
	//vector<STring> vecStr;
	//vecStr.push_back(:hello");
	
	String s1  "hello";
	cout<<"s1="<<s1<<endl;
	//String s2="world";
	cout<<endl<<endl;
	
	s1=String("shenzhen");
	cout<<"s1="<<s1<<endl;

	String s2=",world";

	cout<<"执行move函数之后:"<<endl;
	s1=std::move(s2);//如果对一个有名对象s2执行类move函数，就代表在这之后不会再使用s2了
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;

	return 0;
}
#endif

int main(void)
{
	int a=10;
	int b=120;
	int *pFlag=&a;

	vector<String> vecstr;
	vecstr.push_back("hello");

	if(!vecstr.empty())
	{
		cout<<"vecstr.empty()="<<vecstr.empty()<<endl;
	}

	String s1="hello";
	cout<<"sa1="<<s1<<endl;

	String s2=",world";
	cout<<"执行move函数后:"<<endl;
	s1=std::move(s2);//如果对一一个有名对象s2执行类move函数，就代表之后都不会再使用
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	const int & m=1;//const引用可以绑定到任意值，无法区分左值还是右值
	//int & n=10;//非const的引用只能绑定左值
	int && n=10;//c++11y语法，右值引用
	//int && x=a;//右值引用不能绑定到左值，只能绑定到右值，无效类型
	
	//&(a+b);//右值类型不能取地址
	//int c= a+b;//c左值

	//&(a++);后置返回右值
	
	&(++a);//左值
	
	&pFlag;//左值

	&vecstr[0];//

//	&100;//字面值,右值

	//&String("hello");//匿名对象,右值
	
//	&(s1+s2);//匿名对象，右值
	return 0;
}

