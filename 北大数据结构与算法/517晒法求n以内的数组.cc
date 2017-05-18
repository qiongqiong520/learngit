 ///
 /// @file    517晒法求n以内的数组.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 12:58:38
 ///
 //晒法求n以内的素数
 //把2到n以内的所有数都列出来，然后划掉n以内2的倍数，
 //然后每次从下一个剩下的数，花掉n以内，剩下的数的倍数，最后剩下的数就都是素数
 //
 
#include <iostream>
using std::cout;
using std::endl;
#define MAX_NUM 10000000
char isPrime[MAX_NUM+10];//最终如果isPrime[i]为1
int main()
{
	for(int  i=2;i<=MAX_NUM;++i)//开始假设所有数都是素数都是
		isPrime[i]=1;
	for(int i=2;i<=MAX_NUM;++i){//每次将一个素数的所有倍数标记为费非素数
		if(isPrime[i])//只标记素数的倍数
			for(int j=2*i;j<=MAX_NUM;j+=1)
				isPrime[j]=0;//将素数i的倍数标记为飞素数
	}
	for(int i=2;i<=MAX_NUM;++i)
		if(isPrime[i])
			cout<<i<<endl;
	return 0;
}
