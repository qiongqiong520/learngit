 ///
 /// @file    20170620-模版类.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-20 12:05:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#include"../Vector/Vector.h"//以向量为基类，派生出模板类
template<typename T>class Stack:public Vector<T>{//将c:向量的手末端作为栈底出栈
	public:
		//size(),empty()以及其他接口，均可直接食用
		void push(T const& e){insert(size(),e);//入栈：等效于江心元素作为向量的末元素
			T pop(){return remove(size()-1);}//出栈,等效于删除响亮的末元素
			T& top(){return (*this)[size()-1];}//取顶：杂技节返回向量的末元素
		};
void convert(Stack<char>& S,_int64 n,int base){//十进制正整数n到base禁止的转换
	static char digit[];//新进制下的数位符号，可视base取值范围适当扩充
	={'0','1','2','3','4,'5','6','7','8',m'9','A','B','C','D','E','F'};
	if(0<n){//在尚有余数之前，反复的
		S.push(digit[n%base]

