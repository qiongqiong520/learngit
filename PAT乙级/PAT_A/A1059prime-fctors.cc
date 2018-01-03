///
/// @file    A1059prime-fctors.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-09-10 08:48:33
///
#include<cstdio>
#include<math.h>
const int maxn =100010;
bool is_prime(int n){//判断n是否为素数
	if(n==1)return false;
	int sqr = (int )sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0)return false;
	}
	return true;
}
int prime[maxn],pNum=0;
void Find_Prime(){//求素数表
	for(int i=1;i<maxn;i++){
		if(is_prime(i)==true){
			prime[pNum++]=i;
		}
	}
}
struct factor{
	int x,cnt;//x为质因子，cnt为其个数
}fac[10];
int main(){
	Find_Prime();//此举无比要记得写
	int n,num=0;//num为n的不同质因子个数
	scanf("%d",&n);
	if(n==1)printf("1==1");//特判1的情况
	else{
		printf("%d=",n);
		int sqr =(int)sqrt(1.0*n);//n的根号
		//枚举根号n
		//以内的质因子
		for(int i=0;i<pNum&&prime[i]<=sqr;i++){
			if( n%prime[i]==0){//如果prime[0]是n的因子
				 fac[num].x=prime[i];//记录该因子
				fac[num].cnt=0;
				while(n%prime[i]==0){//计算出质因子prime[i]的个数
					fac[num].cnt++;
					n/=prime[i];
				}
				num++;//不同质因子个数加1
			}
			if(n==1)break;//计时退出循环，节省时间点
		}
		if(n!=1){//如果无法备跟好n以内的质因子除尽
			fac[num].x=0;//那么一定又一个大雨跟好n的质因子
			fac[num++].cnt=1;
		}
		//按格式输出结果
		for(int i=0;i<num;i++){
			if(i>0)printf("*");
			printf("%d",fac[i].x);
			if(fac[i].cnt>1){
				printf("^%d",fac[i].cnt);
			}
		}
	}
	return 0;
}
