 ///
 /// @file    B1002_A+Bfor_ploynomials.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-28 19:05:11
 ///
#include<cstdio>
const int max_n =1111;
double p[max_n]={};

int  main()
{
	int k,n,count=0;
	double a;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		 scanf("%d %lf",&n,&a);
		 p[n]+=a;
	}
	scanf("%d",&k);
	for(int 

