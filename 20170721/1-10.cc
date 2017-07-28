 ///
 /// @file    1-10.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 23:54:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//方案一
int max (int a,int b,int c){
	int m=a;
	if(b>m)m=b;
	if(c>m)m=c;
	return m;
}

//方案2（此程序可修改中止变量扩大到n个整数)
int max(int a,int b,int c){
	int data[3]={a,b,c};
	int m=0;//开始时嘉定data[0]最大
	for(int i=1;i<3;i++)//与其他整数诸葛比较
		if(data[i]>data[m])m=i;//m记录新的最大值
	return data[m];
}

//求3个整数中的最小整数的函数
//方案1
int min(int a,int b,int c){
	int m=a;
	if(b<m)m=b;
	if(c<m)m=c;
	return m;
}
