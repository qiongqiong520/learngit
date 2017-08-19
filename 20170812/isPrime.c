 ///
 /// @file    isPrime.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-12 15:18:36
 ///
#include<stdio.h>
#include<math.h>
int isprime(int);
int main()
{
	 int inumber;
	  printf("请输入一个非负整数: ");
	   scanf("%d",&inumber);
	    if(isprime(inumber))
			   printf("%d是素数!\n",inumber);
		  else 
			     printf("%d不是素数!\n",inumber);
}
int isprime(int a)
{ 
	 int i;
	     for(i=2;i<=sqrt(a);i++)
			   if(a%i==0)
				      return 0;
		   return 1;
}
