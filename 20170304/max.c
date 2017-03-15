 ///
 /// @file    max.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-04 22:37:32
 ///
 
#include<stdio.h>
#include<math.h>

int Max3(int a,int n,int c)
{
	//返回3个整数的最大值
	return a>b?c>a?a:c:b>c?b:c;
}

int DivideAndConquer(int list[],int left,int right)
{
	//分治法求解list[left]到list[right]的最大子咧和
	int MaxleftSum,MaxRightSum;//存放左右子问题的解
	int MaxLeftBorderSum,MaxRightBorderSum;//存放跨分界线的结果

	int LeftBorderSum,RightBorderSum;
	int center,i;
	if(left ===right)
	{//递归终止条件
		if(List[left]>0)
			return List[left];
		else 
			return 0;
	}

	//分的过程
	center = (left+right)/2;//找到中分点
	//递归求解两边子咧和
	MaxleftSum=DivideAndConquer(List,left,center);
	MaxRightSum = DivideAndConquer(List,center+1,right);

	//下面求跨分界线的最大子列和
	MaxLeftBorderSum =0;LeftBorderSum=0;
	for(i=center;i>=left;i--)
	{
		LeftBorderSum  +=List[i];
		if(LeftBorderSum>MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}//左边扫描结束
	
	MaxBorderRightSum=0,RightBorderSum=0;
	for(i=center+1;i<=right;i++)
	{
		RightBorderSum +=List[i];
		if(RightBorderSum>MaxRightBorderSum)
			MaxRightBorderSum=RightBorderSum;
	}//右边扫描结束

	//f返回治的结果
	return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MacxRightBorderSum);
}

int MaxSubseqSum3(int list[],int N)
{
	//保持与前两种算法相同的函数接口
	return DivideAndConquer(List,0,N-1);
}


int main(void)
{
	int N,i;
	int *arr;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",arr);
	}
