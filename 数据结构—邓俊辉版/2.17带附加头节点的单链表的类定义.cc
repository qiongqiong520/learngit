 ///
 /// @file    2.17带附加头节点的单链表的类定义.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-13 21:07:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<class T>//定义在头节点
struct LinkNode{
	T data;
	LinkNode<T> *link;
	LinkNode(LinkNode<T> *ptr=NULL){link=ptr;}
	//仅初始化指针成员的构造函数
	LinkNode(const T& item,LinkNode<T> *ptr=NULL)
	{data=item;link=ptr;}
	//初始化数据域指针成员的构造函数
};

template<class T>
class List:public LinearList<T>{
	public:
		//单链表定义，不用继承也可以实现
		List(){first=new LinkNode<·T>;}//构造函数
		List(const T& x){first =new LinkNode<T> (x);}//复制构造函数
		List(List<T>& L);//复制构造函数
		~List(){makeEmpty();}//析构函数
		void makeEmpty()；//	将链表置为空
		int Length()const;//计算链表的长度
		LinkNode<T>* getHead()const {return firsrt;}//返回附加头节点长度
		LinkNode<T> *Search(T x);//搜索含数据x的元素
		LinkNode<T> *Locate(int i);//搜索第i元素的地址
		bool setData(int i,T& x)const;//取出第i饿元素的值
		void setdata(int i,T& x);//用修改第i个元素的值
		bool Remove(int i,T& x);//删除第i个元素，x返回该元素的值
		bool IsEmpty() const{//潘表是否为空，空则返回该元素位置
