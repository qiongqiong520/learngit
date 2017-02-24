///
/// @file    operator.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-24 14:41:22
///
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class CharArr{
	public:
		CharArr(int size)//默认构造函数
			:_len(size)
			 ,_pstr(new char[_len])
			{
				cout<<"CharArr(int)"<<endl;
			}
		~CharArr()
		{
			cout<<"~CharArr()"<<endl;
			delete []_pstr;
		}
		char & operator [](int idx)
		{
			cout<<endl<<"char & operator[] (int)"<<endl;
			static char ch='\0';
			if(idx>=0&&idx<_len)
				return _pstr[idx];
			else
			{
				cout<<"下标越界"<<endl;
				return ch;
	
			}
		}
#if 0
	 void display()
	{
		for(int idx =0;idx!=0_len;++idx)
		{
			cout<<_pstr[idx];
		}
	}
#endif

	private:
		int _len;
		char * _pstr;
};
int main(void)
{
	//把string当成插入类型的容器
string s1="hello world";
	const char * pstr="Hello ,world";
	CharArr ca(10);

	int len=strlen(pstr);
	for(int idx =0;idx!=len;++idx)
	{
		ca[idx]=pstr[idx];
	}
	for(int idx =0;idx!=len;++idx)
	{
		cout<<ca[idx];
	}

	for(int idx =0;idx!=s1.size();++idx)
	{
		cout<<s1[idx];
	}
	cout<<endl;
	return 0;
}
