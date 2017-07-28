 ///
 /// @file    B1047团体编程赛.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-15 19:48:58
 ///
 
#include<stdio.h>
int main(int argc,char* argv[]){
	int n;
	while(scanf("%d",&n)!=EOF){
		int team[10001]={0};
		for(int i=0;i<n;i++){
			int t,m,g;
			scanf("%d-%d",&t,&m);
			scanf("%d",&g);
			team[t]+=g;
		}
		int max=-1,index=-1;
		for(int i=0;i<10000;i++){
			if(max<team[i]){
				max=team[i];
				index=i;
			}
		}
		printf("%d %d\n",index,max);
	}
	return 0;
}
