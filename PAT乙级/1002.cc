 ///
 /// @file    1002.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 14:30:47
 ///
 
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	char num[102];
	char *output[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	while(gets(num)){
		int sum=0;
		for(int i=0;num[i]!='\0';i++){
			sum+=num[i]-'0';
		}
		int ret[10]={-1};
		int k=0;
		while(sum>0){
			ret[k]=sum%10;
			sum/=10;
			k++;
		}
		for(int i=k-1;i>0;i--)
		{
			printf("%s  ",output[ret[i]]);
		}
		printf("%s\n",output[ret[0]]);
	}
	return 0;
}

