 ///
 /// @file    hfm.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-29 18:22:31
 ///
/*
 * name：哈夫曼编码源代码
 * 实现过程：着先通过huffmantree（）函数构成构造哈夫曼树，然后再煮函数main中
 * 自底向上开始就是从数组序号为零的节点开始向上层层判断，若在敷节点左侧，则置码为1，最后输出生成的编码
 */

#include<stdio.h>
#include<stdlib.h>
#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1

typedef struct
{
	int bit[MAXBIT];
	int start;
}HCodeType;//编码结构体
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	int value;
}HNodeType;//节点结构体
void HuffmanTree(HNodeType HuffNode[MAXNODE],int n)
{
	int i,j,m1,m2,x1,x2;
	for(i=0;i<2*n-1;i++)
	{
		HuffNode[i].weight=0;//权值
		HuffNode[i].parent=-1;
		HuffNode[i].lchild=-1;
		HuffNode[i].rchild=-1;
		HuffNode[i].value=i;//实际值，可根据情况替换字母
	}
	//输入n个叶子结点的权值
	for(i=0;i<n;i++)
	{
		printf("Please input weight of leaf node %d:\n",i);
		scanf("%d",&HuffNode[i].weight);
	}
	for(i=0;i<n-1;i++)
	{
		m1=m2=MAXVALUE;
		x1=x2=0;
		for(j=0;j<n;j++)
		{
			if(HuffNode[j].weight<m1&&HuffNode[j].parent==-1)
			{
				m2=m1;
				x2=x1;
				m1=HuffNode[i].weight;
				x1=j;
			}
			else if(HuffNode[j].weight<m2&&HuffNode[j].parent==-1)
			{
				m2=HuffNode[j].weight;
				x2=j;
			}
		}
		//设置找到的两个子节点x1、x2的敷节点信息
		HuffNode[x1].parent=n+i;
		HuffNode[x2].parent=n+i;
		HuffNode[n+i].weight=HuffNode[x1].weight+HuffNode[x2].weight;
		HuffNode[n+i].lchild=x1;
		HuffNode[n+i].rchild=x2;

		printf("x1.weight and x2.weight in round  %d：%d ,%d\n",i+1,HuffNode[i].parent,HuffNode[i].rchild,HuffNode[i].lchild,HuffNode[i].rchild,HuffNode[i].value,HuffNode[i].weight);
		}

	void decodeing(char string[],HNodeType Buff[],int Num)
	{
	 	int i,tmp=0,code[1024];
		int m=2*Num-1;
		char *nump;
		char num[1024];
		for(i=0;i<strlen(string);i++)
		{
			if(string[i]=='0')
				num[i]=0;
			else
				num[i]=1;
		}
		i=0;
		nump=&num[0];
		while(nump<(&num[strlen(string)]))
		{
			tmp=m-1;
			while((Buff[tmp].lchild!=-1)&&(Buff[tmp].rchild!=-1))
			{
				if(*nump==0)
				{
					tmp=Buff[tmp].lchild;
				}
				else tmp=Buff[tmp].rchild;
				nump++;
			}
			printf("%d",Buff[tmp].value);
		}
	}
	int main(void)
	{
		HNodeType HuffNode[MAXNODE];
		HCodeType HuffCode[MAXLEN],cd;
		int i,j,c,p,n;
		char pp[100];
		printf("Please input n::\n");
		scanf("%d",&n);
		HuffmanTree(HuffNode ,n);

		for(i=0;i<n;i++)
		{
			cd.start=n-1;
			c=i;
			p=HuffNode[c].parent;
			while(p!=-1)
			{
				if(HuffNode[p].lchild==c)
					cd.bit[cd.start]=0;
				else
					cd.start--;
				c=p;
				p=HuffNode[c].parent;
			}
			for(j=cd.start+1;j<n;j++)
			{HuffCode[i].bit[j]=cd.bit[j];}
			HuffCode[i].start=cd.start;
		}
		for(i=0;i<n;i++)
		{
			printf("%d \s HuffmanTree  Code is:",i);
			for(j=HuffCode[i].start+1;j<n;j++)
			{
				printf("5d",HuffCode[i].bit[j]);
			}
			printf("start :%d",HuffCode[i].start);
			printf("\n");
		}
		/*
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
			{
				printf("%d",HuffCode[i].bit[j]);
			}
			printf("\n");
		}*/
		printf("Decoding ?Please Enter code:\n");
		scanf("%s",&pp);
		decoding(pp,HuffNode,n);
		getch();
		return 0;
	}
			
