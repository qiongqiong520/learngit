 ///
 /// @file    2017_06_08Fibonacci.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-08 21:43:03
 ///
 
#include "..\fibonacci\Fib.h"//引入Fib数列类
//Fibonacci查找算法版本A：在有序向量的区间内查找元素e,0<=lo<=hi<=_size;
template<typename T>static Rank fibSearch(T* A,T const& e,Rank lo,Rank hi){
	Fib fib(hi-lo);//用o(log_phi(n=hi-lo)时间创建Fib数列
	while(lo<hi){//没两步迭代可能要做的 两次判断比较，有三个分支
		while(hi-lo<fib.get())fib.prev();//通过向前顺序查找（分摊o(1)至多迭代几次
		Rank mi=lo+fib.get()-1;//确定形如Fib（）-1的轴点
		if（e>A[mi])hi=mi;//深入前半段[lo,mi]继续查找
		else if(A[mi]<e)lo=mi+1;//在mi除命中
		else return mi;//在mi出命中A
	}//成功查找可以提前终止
return -1;//查找失败
}//由多个命中元素时，不能保证返回值的最大者，失败时，简单的返回-1，而不能指望失败的位置

