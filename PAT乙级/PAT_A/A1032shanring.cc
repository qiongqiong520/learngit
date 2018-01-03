 ///
 /// @file    A1032shanring.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-10 10:00:26
 ///
#include<stdio.h>
#include <cstring>
const int maxn = 100010;
struct NODE{
	char data;//数据域
	int next;//指针域
	bool flag;//结点是否在第一条链表中出现
}node[maxn];
int main(){
	for(int i=0;i<maxn;i++){
		node[i].flag=false;
	}
	int s1,s2,n;
	scanf("%d%d%d",&s1,&s2,&n);
	int address,next;
	char data;//数据
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&address,&data,&next);
		node[address].data=data;
		node[address].next=next;
	}
	int p;
	for(p=s1;p!=-1;p=node[p].next){
		node[p].flag=true;
	}
	for(p=s2;p!=-1;p=node[p].next){
		if(node[p].flag==true)break;
	}
	if(p!=-1){//如果第二条链表还没有到达结尾，说明找到了共同结点
	printf("%05d\n",p);
	}else{
		printf("-1\n");
	}
	return 0;
}
