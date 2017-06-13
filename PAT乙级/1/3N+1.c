 ///
 /// @file    3N+1.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 14:22:13
 ///
 
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int k=0;
		while(n>1){
			if(n%2==0)
			{
				n/=2;
			}else{
				n=(3*n+1)/2;
			}
			k++;
		}
		printf("%d\n",k);
	}
	return 0;
	system("pause");
}
