 ///
 /// @file    计算海岛高度.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-03 23:52:31
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//1.1计算海岛高度
float islandHeight(float d1,float d2,float d,float h){//后表却步,前表却步,表间,表高
	float pha=d1-d2;//二去表相减为，以为法
	float shi= d*h;//前后表相减为表间，以表高乘之为实
	return shi/pha+h;//以法除之，加表高，既是岛高积步
}
//1.2海岛距离算法
float islandDistance(float d1,float d2,float d){
	float shi =d2*d;
	float pha=d1-d2;
	return shi/pha;//除之得三万七百五十步
}

//包含n个元素的旗袍排序
//1-7试用c++语言描述一个循环分支,分支，子函数调用,甚至递归结构的算法

//1.3包含循环、分支、子函数调用递归结构，但具有常熟时间复杂度的算法
void 01(unsigned int n){
	for(unsigned int i=0;i<n;i+=1+n/2013){//循环:迭代至多2013次
UNREACHABLE:
		if(1+1!=2)goto UNREACHABLE;
		if(n*n<0)doSomething(h);//分支：条件永非,调用无效
		if((n+i)*(n+i)<4*n*i)doSomething(n);
		if(2==(n*n)%5)01(n+1);
		int f=fib(n);
		if(12<n&&(sqrt(f)*sqrt(f)==f))01(n-1);
	}
}

