 ///
 /// @file    1001害死人不偿命的3N+1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-16 16:28:23
 ///
#include<cstdio>

int main()
{
	int n,step=0;
	scanf("%d",&n);
	while(n!=1){//循环判断n是否为1
		if(n%2==0)n=n/2;//如果是偶数
		else n=(3*n+1)/2;//如果n是奇数
		step++;
	}
	printf("%d\n",step);
	return 0;

}
