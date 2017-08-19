 ///
 /// @file    B1010_一元多项式求解.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-28 11:44:53
 ///
#include<cstdio>

int main()
{
	int a[1010]={0};
	int k,e,count = 0;//l为系数，e为指数，count计数不为零的导数项个数
	while(scanf("%d%d",&k,&e)!=EOF){//输入系数和指数直到文件末尾
		a[e]=k;
	}
	a[0]=0;//零次项求到之后直接为零
	for(int i=1;i<=1000;i++){//从一次项开始枚举
		a[i-1]=a[i]*i;//求 导公式
		a[i]=0;//此举不可省
		if(a[i-1]!=0)count++;//count++技术不为零的导数项个数
	}
	if(count==0)
		printf("0 0");//特判
	else{
		for(int i=100;i>=0;i--){//指数从高到低输出
			if(a[i]!=0){
				printf("%d %d",a[i],i);
				count--;
				if(count!=0)printf(" ");
			}
		}
	}
	return 0;
}
