 ///
 /// @file    A1042shuttingmachine.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-20 13:15:10
 ///
#include<cstdio>
const int N=54;
char mp[5]={'S','H','C','D','J'};//拍的编号与花色的对应关系
char start[N+1],end[N+1],next[N+1];//next数组存放每个位置上的排毒关系在操作后的位置

int main(){
	int K;
	scanf("%d",&K);
	for(int i=1;i<=N;i++){
		start[i]=i;//初始化拍的编号
	}
	for(int i=1;i<=N;i++){
		scanf("%d",&next[i]);//输入每个位置上的牌在操作后的位置
	}
	for(int step=0;step<K;step++){
		//执行k此操作
		for(int i=1;i<=N;i++){
			end[next[i]]=start[i];//把第i个位置的牌编号村雨位置next上
		}
		for(int i=1;i<=N;i++){
		start[i]=end[i];//把end数组复制给start数组以提供下次操作使用
		}
	}	
	for(int i=1;i<=N;i++){
	if(i!=1)printf(" ");//控制输出格式
	start[i]--;
	printf("%c%d",mp[start[i]/13],start[i]%13+1);//输出结果
	}
	return 0;
	}
