 ///
 /// @file    2.17.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-13 22:03:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<class T>//定义在头文件中
struct LinkNode{//链表结点类的定义
	T data;//数据域
	LinkNode<T> *link;//链指针域
	LinkNode(const T& item,LinkNode<T> *ptr=NULL)
	{data=item;link=ptr;}//初始化数据域指针成员的构造函数
};

template<class T>
class list:public LinearList<T>{//单链表定义，不用继承也可以实现
	public：
		List(){first=new LinkNode<T>;}//构造函数
	List(const T& x){first =new LinkNode<T>(x);}//复制构造函数
	～List(){makeEmpty();}//析构函数
	void makeEmpty();//将链表置为空表
	int length()const;//计算链表的长度
	LinkNode<T> *getHead() const {return first;}//返回附加头节点长度
	LinkNode<T> *Search(T x);//搜索含数据元素x的元素
	LinkNode<T> *Locate(int i);//搜索第i个元素的地址
	bool setData(int i,T& x)const;//取出第i个元素的地址
	void Insert(int i,T& x);//在第i个元素后插入x
	bool Remove(int i,T& x);//删除第i 个元素，x空则返回true
	bool IsEmpty()const
	{return first->link==NULL?true:false;}
	bool IsFull()const {return false;}//判表满否？不满则返回false；
	void Sort();//排序
	void input();//输入
	void output();//输出
	List<T> & operator=(List<T>& L);//重载函数：赋值
	protected:
	LinkNode<T> *first;//链表的头指针
};
