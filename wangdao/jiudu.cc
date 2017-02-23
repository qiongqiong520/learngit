 ///
 /// @file    jiudu.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 00:37:45
 ///
 
#include <iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
int tree[200];
int FindRoot(int t)//寻找到点x的跟节点
{
	if(Tree[t]==-1)
	return t;
	else{
			int tmp=FIndRoot(Tree[t]);
			Tree[t]=tmp;
			return tmp;
		}
}

struct Node;//定义点的结构体
{
	double x;//点的横坐标
	double y;//点的纵坐标
}Node[100];
struct edge//定义边的结构体
{
	int node1;//、边的一个顶点
	int node2;//边的另一个顶点
	double dis;//边的长度
	bool operator(const edge&a)const//重载<操作符>
	{
		return dis<a.dis;
	}edge[6000];
int main(void)
{
	int n;
	while(cin>n)
	{
		if(n==0)
			break;
		for(int i=1;i<=n;i++)//初始化是每一个点成为一个孤立的点
		{
			Tree[i]=-1;
		}
		for(int i=1;i<=n;i++)//输入每个点的坐标
		{
			//double s,y;
			cin>>Node[i].x>>Node[i].y;
			}
		int edgesize =0;//记录图中有多少条边
		for(int i=0;i<=n;i++)//根据每个点的坐标，来求每个
