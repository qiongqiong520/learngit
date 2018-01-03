 ///
 /// @file    A1001ab-format.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-08 13:29:27
 ///
#include<cstdio>
int num[10];
int main(){
	int a,b,sum;
	scanf("%d%d",&a,&b);
	sum=a+b;//将a+b复制给sum
	if(sum<0){//sum为负数时，输出负号并取sum的相反数
		printf("-");
		sum=-sum;
	}
	int len=0;//len存放sum的长度
	if(sum==0)num[len++]=0;//sum为0时特殊处理
	//将sum存入水num【】中，其中sum的地位存放到怒目[]的地位
	while(sum){
		//将sum的末位sum%10	存放到num[len]，然后len++
		num[len++]=sum%10;
		sum/=10;//去除sum的末位
	}
	for(int k=len-1;k>=0;k--){//从高位开始输出
		printf("%d",num[k]);
		if(k>0&&k%3==0)printf(",");//没3位输出一个逗号,最后一位除外
	}
	return 0;
}

