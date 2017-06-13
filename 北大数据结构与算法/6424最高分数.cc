 ///
 /// @file    6424最高分数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-13 20:45:51
 ///
 
#include <iostream>

int main()
{
	int n, score,temp=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&score);
		if(score>=0&&score<=100)
		{
			if(score>=temp)
				temp=score;
		}
	}
	printf("%d\n",temp);
}
			
			
