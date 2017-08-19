 ///
 /// @file    A1009productofpolynomail.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 13:41:36
 ///

#include <cstdio>
struct Poly{
	int exp;//指数
	double cof;//系数
}poly[1001];//第一个多项式

double ans[2001];//存放结果
int main(){
	int n,m,number=0;
	scanf("%d",&n);//第一个多项式中菲林系数的多项式
	for(int i=0;i<n;i++){
		scanf("%d %lf",&poly[i].exp,&poly[i].cof);//第一个多项式的指数和系数
	}
	scanf("%d",&m);//第二个多项式中非零系数的项数
	for(int i=0;i<m;i++){
		int exp;
		double cof;
		scanf("%d %lf",&exp,&cof);//第二个多项式的指数和系数
		for(int j=0;j<n;j++){//与第一个多项式中的每一项相乘
			ans[exp+poly[j].exp]+=(cof*poly[j].cof);
		}
	}
	for(int i=0;i<=2000;i++){
		if(ans[i]!=0.0)number++;//累计非零系数的项数
	}
	printf("%d",number);
	for(int i=2000;i>=0;i--){//输出
		if(ans[i]!=0.0){
			printf(" %d %.lf",i,ans[i]);
		}
	}
	return 0;
}
