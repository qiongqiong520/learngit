 ///
 /// @file    A1065A+B_and_C.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-28 10:20:42
 ///
 //
 //
#include<cstdio>
int main(){
	int T,tcase = 1;
	scanf("%d",&T);
	while(T--)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long res =a+b;
		bool flag;
		if(a>0&&b>0&&res<0)flag = true;//正溢出为true
		else if(a<0&&b<0&&res>=0)flag =true;//负溢出为flase
		else if(res>c)flag = true;//无益处时，A+B>c时为true
		else flag=false;
		if(flag == true){
			printf("Case #%d:true\n",tcase++);
		}else {
			printf("Case #%d:flase\n",tcase++);
		}
	}
	return 0;
}
