 ///
 /// @file    打印沙漏.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 13:24:55
 ///
 
#include<stdio.h>

int main(int argc,char* argv[]){
	int n;
	char c;
	while(scanf("%d %c",&n,&c)!=EOF){
 		if(n==1){
			printf("%c\n",c);
			printf("0\n");
			return 0;
		}
		int i=0;
		int sum = 1,sumtemp =0;
		while(sum<=n){
			sumtemp =sum;
			sum+=(2*++i+1)*2;
		}
		i--;
		for(int j=i;j>=0;j--)
		{
	 		for(int k=0;k<i-j;k++)printf(" ");
			for(int k=0;k<2*j+1;k++)printf("%c",c);
			printf("\n");
		}
		for(int j=1;j<=i;j++)
		{
			for(int k=0;k<i-j;k++)printf(" ");
			for(int k=0;k<2*j+1;k++)printf("%c",c);
			printf("\n");
		}
		printf("%d\n",n-sumtemp);
	}
	return 0;
}
