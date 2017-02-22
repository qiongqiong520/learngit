///
/// @file    student.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-20 14:41:11
///
#include<string.h>
#include<stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//只能生成栈对象，
//

class Student{
	public:
		Student (int no,char * name)
			:_no(no)
			 ,_name(new char[strlen(name)+1])
	{
		strcpy(_name,name);
	}
		void print()
		{
			cout<<"学号：“<<_no<<endl;
			cout<<"姓名："<<_name<<endl;
		}
		//函数重载
		void * operator new(size_t size)
		{
			cout<<"void * operator new(size_t)"<<endl;
			void *p = malloc(size);
			return p;
		}
		
		void operator delete(void *p)
		{
			cout<<"operstor delete(void*)"<<endl;
			void *p =malloc(size);
			return p;
		}

	private:
		void * operator new(size_t size);
		void operator delete(void *p);
		~Student()
		{
			cout<<"~Student()"<<endl;
			deletc []_name;
		}
	public:
		void destory()
		{
			delete this;
		}

	private:
		int _no;
		char * _name;
};

int main(void)
{
	Student  *s1 =new Student(100,"MIke");
	s1->print();
	//delete s1;
	s1->destory();
	return 0;
}


