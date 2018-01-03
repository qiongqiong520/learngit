 ///
 /// @file    B1019-A1069数字黑洞.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-10 08:39:48
 ///
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){//递减排序
	return a>b;
}
void to_array(int n,int num[]){//将n的每一位存到怒骂数组中
	for(int i=0;i<4;i++){
		num[i]=n%10;
		n/=10;
	}
}
int to_number(int num[]){
	int sum =0;
	for (int i=0;i<4;i++){
		sum =sum*10+num[i];
	}return sum;
}
int main(){
	//min和max分别表示递增排序和递减排序湖得到的最小和最大值
	int n,MIN,MAX;
	scanf("%d",&n);
	int num[5];
	while(1){
		to_array(n,num);
		sort(num,num+4);//对num中数组从小到大排序
		MIN=to_number(num);
		sort(num,num+4,cmp);
		MAX=to_number(num);
		n=MAX-MIN;//得到下一个数
		printf("%04d - %04d = %04d\n",MAX,MIN,n);
		if(n ==0 ||n==6174)break;
	}
	return 0;
}
