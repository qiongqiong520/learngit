 ///
 /// @file    B1046划拳.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-11 23:13:50
 ///
#include<cstdio>

int main()
{
	int n,failA=0,failB=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a1,a2,b1,b2;
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		if(a1+b1==a2&&a1+b1!=b2){//甲猜中乙没猜中
			failB++;//乙输
		}
		else if(a1+b1!=a2&&a1+b1==b2){//甲没有猜中乙猜中
			failA++;
			//甲输
		}
	}
	printf("%d %d\n",failA,failB);
	//输出结果
	return 0;
}
