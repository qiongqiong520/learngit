 ///
 /// @file    dfs.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-10 10:23:59
 ///
 
#include <cstdio>
const int maxn =100010;
int n,V,maxValue=0;
int w[maxn],c[maxn];
void DFS(int index,int sumW,int sumC){
	if(index==n){
		if(sumW<=V&&sumC>maxValue){
			maxValue =sumC;
		}
		return;
	}
	DFS(index+1,sumW,sumC);
	DFS(index+1,sumW+w[index],sumC+c[index]);
}
int main(){
	scanf("%d%d",&n,&V);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	DFS(0,0,0);
	printf("%d\n",maxValue);
	return 0;
}
