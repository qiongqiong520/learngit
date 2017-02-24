///
/// @file    operator.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-24 14:41:22
///
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArr{
	public:
		CharArr(int size)
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
			static char ch='\0';
			if(idx>=0&&idx<_len)
				return _pstr[idx];
			else
			{
				cout<<"下标越界"<<endl;
				return ch;
			}
	void display()
	{
		for(int idx =0;idx!=0_len;++idx)
		{
			cout<<_pstr[idx];
		}
	}
	private:
		int _len;
		char * _pstr;
};

int test(void)
{
	const char * pstr="Hello ,world";
	int len=strlen(pstr);
	CharArr ca(10);

	for(int idx =0;idx!=len;++idx)
	{
		ca[idx]=pstr[idx];
	}
	return 0;
}

int main(void)
{
	//把string当成插入类型的容器
	string s1="hello world";

	for(int idx =0;idx!=size;)
	{
		cout<<s1[idx];
	}
