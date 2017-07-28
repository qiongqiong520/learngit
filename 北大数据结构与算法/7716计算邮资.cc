 ///
 /// @file    7716计算邮资.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-18 23:34:09
 ///
#include<cstdio>
int main()
{
	int n,fee=0;
	char c;
	scanf("%d %c",&n,&c);
	if(n<=1000)
	{
	 	if(c=='y')
			printf("13\n");
		else
			printf("8\n");
	}
	else{
	  	if(c=='y')
		{
	 	 	if((n-1000)%500==0)
				fee=13+(n-1000)/500*4;
			else
				fee=17+(n-1000)/500*4;
		}
		else{
	  		if((n-1000)%500==0)
				fee=8+(n-1000)/500*4;
			else
			fee=12+(n-1000)/500*4;
		}
	}
	printf("%d\n",fee);
	return 0;
}
