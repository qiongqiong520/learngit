 ///
 /// @file    A1011world-cup-betting.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-25 13:18:49
 ///
 
#include <cstdio>
char S[3]={'W','T','L'};
int main(){
	double ans=1.0,tmp,a;
	int idx;//记录每行最大数字的下标
	for(int i=0;i<3;i++){
		tmp=0.0;
		for(int j=0;j<3;j++){//寻找该行最大数字存于tmp
			scanf("%lf",&a);
			if(a>tmp){
				tmp=a;
				idx=j;
			}
		}
		ans*=tmp;//按公式累乘
		printf("%c",S[idx]);//输出对应的比赛结果
	}
	printf("%.2f",(ans*0.65-1)*2);//输出最大收益
	return 0;
}
