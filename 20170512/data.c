 ///
 /// @file    data.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 13:22:33
 ///
#include<stdio.h>
#include<stdlib.h>

//calulator
int main()
{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int year,mon,day;
	while(fflush(stdin),scanf("%d%d%d",&year,&mon,&day)!=EOF)
	{
		printf("%d-%d-%d\n",year,mon,day);
	}
	system("pause");
	return 0;
}
