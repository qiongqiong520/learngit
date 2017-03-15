 ///
 /// @file    clock.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-04 17:42:04
 ///
#include<stdio.h>
#include<time.h>

clock_t start,stop;
/*clock_t是clock（）函数返回的变量类型*/
double duration;

int main()
{
	start =clock();
	MyFunction();
	stop=clock();
	duration =((double)(stop-start))/CLK_TCK;//CLK_TCK机器时钟每秒所走的时钟打点数
	return 0;
}
