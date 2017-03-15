 ///
 /// @file    tck.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-04 20:40:05
 ///
#include<stdio.h>
#include<time.h>
#include<math.h>
clock_t start,stop;
double duration;
#define MAXN 10//多项式最大项数
#define CLK_TCK 18.2
#define MAXK 1e7//被测函数最大重复次数
double f1(int n,double a[],double x);
double f2(int n,double a[],double x);

int main()
{
  	int i;
	double a[MAXN];
	for(i=0;i<MAXN;i++)a[i]=(double)i;

	start =clock();
	for(i=0;i<MAXK;i++)
		f1(MAXN-1,a,1.1);
	stop=clock();
	duration =((double)(stop -start))/CLK_TCK/MAXK;
	printf("ticks1 =%f\n",(double)(stop -start));
	printf("duration =%6.2f\n",duration);

	start =clock();
	f2(MAXN-1,a,1.1);
	stop=clock();
	duration =((double)(stop -start))/CLK_TCK;
	printf("ticks1 =%f\n",(double)(stop -start));
	printf("duration =%6.2f\n",duration);
	return 0;
}
