/<F5>//
/// @file    String.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-25 19:29:51
///
#include<stdio.h>
#include<
#include<math.h>
#include <iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;

class String{
	friend bool operator<<(std::ostream &os ,const String &rhs);
	friend bool operator<<(std::istream &is ,const String &rhs);
	friend bool operator==(const String &,const String &);
	friend bool operator!=(const String & ,const String &);
#if 0
	friend bool operator<(const String &,const String &);
	friend bool operator>(const String & ,const String &);
	friend bool operator<=(const String &,const String &);
	friend bool operator>=(const String &,const String &);
#endif
	public:
	String()//默认构造函数                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
		:_pstr(new char[1])//浅拷贝
	{
	}
	String(const char *pstr)
		:_pstr(new char[strlen(pstr)+1])//深拷贝
	{
		strcpy(_pstr,pstr);
	}

	String(const String &rhs)
		:_pstr(new char[strlen(rhs._pstr)+1])
	{
		strcpy(_pstr,rhs._pstr);
	}
	~String()//析构函数，程序结束自动销毁栈空间
	{
		delete []_pstr;
	}

	String & operator=(const String &cc)
	{
		return strcmp(_pstr,cc._pstr);
	}
#if 0
	String &operator=(const char *cc)
	{
		if(*this ==
#endif
	//复合复制运算符最好一成员函数形式重载
	String &operator+=(const String &rhs)
	{
		strcpy(_pstr,rhs._pstr);
		return *this;
	}

	String &operator+=(const char *cc)
	{

	}
	//std::size_t 是sizeofalignof草造福返回的一种无符号整数类型
	char &operator[](std::size_t index)
	{
		cout<<endl<<"char &operator[](std::size_t index)"<<endl;
		static char ch ='\0';
		if( index>=(const std::size_t)0 && index<(std::size_t)(strlen(_pstr)+1))
			return _pstr[index];
		else{
			cout<<"下标越界"<<endl;//参数不合法
			return ch;//输出空字符不能直接return\0
		}
	}
	const char &operator[](std::size_t index)const
	{

	}

	std::size_t size() const;
	const char* c_str() const;


	void print()
	{
		cout<<_pstr<<endl;
	}
	private:
	char *_pstr;
	int _len;
};

bool operator==(const String &lhs,const String &rhs)
{
	return  lhs==rhs;
}
#if 0
bool operator!=(const String &lhs ,const String &rhs)
{
	return !(lhs==rhs);
}

bool operator<(const String &lhs,const String &rhs)
{
	return rhs<lhs;
}
bool operator>(const String & lhs,const String &rhs)
{
	return lhs>rhs;
}
bool operator<=(const String & lhs,const String &rhs)
{
	return !(rhs<lhs);
}
bool operator>=(const String & lhs,const String &rhs)
{
	return !(lhs<rhs);
}

bool operator<<(std::ostream &os ,const String &rhs)
{
	os<<rhs._pstr;
	return os;
}
bool operator<<(std::istream &is ,const String &rhs)
{
	is>>rhs._pstr;
	while(is.get()!='\0');
		is>>rhs._pstr;
	return is;
}
String operator+(const String &lhs,const String &rhs)
{
	return  strcat(lhs._pstr,rhs._pstr);
}
String operator+(const String &lhs,const char *rhs);
#endif

int main(void)
{
	String s1="hello world";
	s1.print();

	String s2;
	s2=s1;
	cout<<"S2= "<<s2;

	cout<<"S2= "<<s2;

	cout<<"not equal?";

	return 0;
}

