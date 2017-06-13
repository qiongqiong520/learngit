 ///
 /// @file    2.23分二查找算法.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-08 22:25:21
 ///
 template<typename T>static Rank binSearch(&* A,T const& e,Rank lo,Rank hi){
	 while(1<hi-lo){//每步迭代仅需一次比较判断，有两个分支，成功查找不能提前终止
		 Rank mi=(lo+hi)>>1;//以中点为轴点
		 （e<A[mi])?hi=mi:lo=mi;//井壁较厚确定深入[lo.hi]或【幂，hi）
	 }//出口时hi=lo+1,查找成功时返回对应的秩；否则统一返回1
	 return (e==A[lo])?lo:-1;//查找成功时返回对应的秩，否则统一返回-1
 }//由多个名字元素时，不能保证返回秩的最大者，查找失败时，简单的返回-1.而不能指示失败的位置
template<typename T>static Rank binSearch(&* A,T const& e,Rank lo,Rank hi){
	while(1<hi-lo){//每步迭代仅需一次比较判断，有两个分支，成功查找不能提前终止
		Rank mi=(lo+hi)>>1;//以中点为轴点
		（e<A[mi])?hi=mi:lo=mi;//井壁较厚确定深入[lo.hi]或【幂，hi）
	}//出口时hi=lo+1,查找成功时返回对应的秩；否则统一返回1
	return (e==A[lo])?lo:-1;//查找成功时返回对应的秩，否则统一返回-1
}//由多个名字元素时，不能保证返回秩的最大者，查找失败时，简单的返回-1.而不能指示失败的位置

