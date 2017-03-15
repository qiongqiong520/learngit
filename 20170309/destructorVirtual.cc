 ///
 /// @file    destructorVirtual.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 22:42:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
	public:
 		Base(const char* pdata)
			:_pdata(new char[strlen(pdata)+1])
		{
			strcpy(_pdata,pdata);
		}
		void display()
		{
			cout<<"Base::display()"<<endl;
		}
	//一旦将基类的析构函数设置为虚函数之后
	//派生类的析构函数自动成为虚函数，即使不加virtual关键字
 	 	virtual 
		~Base()
		{
 		 	cout<<"~Base()"<<endl;
			delete []_pdata;
		}
	private:
		char *_pdata;
};

class Child :public Base
{
	public:
 	 	Child(const char* p1,const char* p2)
	 		:Base(p1)
			 ,_pdata2(new char[strlen(p2)+1])
	{
		strcpy(_pdata2,p2);
	}
	 	~Child()
		{
	 		cout<<"~Child()"<<endl;
			delete []_pdata2;
		}
	private:
		char * _pdata2;
};
int main(void)
{
	cout<<"sizeof(Base)="<<sizeof(Base)<<endl;
	cout<<"sizeof(Child)="<<sizeof(Child)<<endl;

	//Base base("hello");
	//当基类指针指向派生类对象，在释放派生类对象时
	//发现只是执行类基类的析构函数
	//
	Base *p=new Child("hello","world");
	delete p;

	return 0;
}
