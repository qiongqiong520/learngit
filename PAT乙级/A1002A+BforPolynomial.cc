 ///
 /// @file    A1002A+BforPolynomial.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-19 19:24:30
 ///
 
#include <cstdio>
const int max_n =1111;
double p[max_n]={};
int main(){
	int k,n,count=0;
	double a;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %lf",&n,&a);
		p[n]+=a;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %lf",&n,&a);
		p[n]+=a;
	}
	for(int i=0;i<max_n;i++){
		if(p[i]!=0) 
			count++;
	}
	printf("%d",count);
	for(int i=max_n-1;i>=0;i--){
		if(p[i]!=0)
			printf("%d %.lf",i,p[i]);
	}
return 0;
}
