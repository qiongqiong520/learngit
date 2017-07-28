 ///
 /// @file    20170713复合类.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-13 14:49:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class List;//list类的前世声明
class LinkNode{//节点类定义
	friend class List;//声明List类为友元类
	private:
	int data;
	LinkNode *link;
};
class List{
	public:
	private:
		LinkNode * first;
};

