 ///
 /// @file    B1032_挖掘机技术哪家强.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-26 12:44:08
 ///
#include<cstdio>

const int maxn = 100010;
int school[maxn]={0};//记录每个学校的总分数
int main()
{
	int n,schID,score;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&schID,&score);
		school[schID]+=score;//学校总分加score
	}
	int k=1,MAX = -1;//最高总分的学校ID中选出一个最高分的
	for(int i=0;i<=n;i++){//从所有学校中选出一个最高的一个
		if(school[i]>MAX){
			MAX = school[i];
			k =i;
		}
	}
	printf("%d %d\n",k,MAX);//输出最高分的学校ID以及其总分
	return 0;
}

