 ///
 /// @file    A1019general-palindromic-number.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-29 22:36:52
 ///
 
#include <cstdio>
bool Judge(int z[],int num){//判断数组z所存的数是否为回文数，怒美位数
	for(int i=0;i<=num/2;i++){
		if(z[i]!=z[num-1-i]){//如果位置i与其对称位置num-1-i位置不相同
			return false;
		}
	}
	return true;//所有对称位置相同
}
int main(){
	int n,b,z[40],num=0;//数组z存放转换结果，num为其位数
	scanf("%d%d",&n,&b);//输入题目给定的n域b
	do{//将n转换为b禁止，结果村域数组z中
		z[num++]=n%b;//除基取余
		n/=b;
	}while(n!=0);//当n变为0时退出循环
	bool flag=Judge(z,num);//判断数组z保存的数是否回文
	if(flag==true)printf("Yes\n");//回文
	else printf("No\n");//不回文
	for(int i=num-1;i>=0;i--){//输出数组z
	printf("%d",z[i]);
	if(i!=0)printf(" ");
}
return 0;
}
