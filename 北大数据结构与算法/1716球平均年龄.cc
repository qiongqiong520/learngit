 ///
 /// @file    1716球平均年龄.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-13 20:17:44
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int n,age,sum=0;
	cin>>n;
	if(n>=1&&n<=100)
	for(int i=0;i<n;i++)
	{
	 	cin>>age;
		if(age>=15&&age<=25)
			sum +=age;
	}
	printf("%.2f\n",(float)sum/n);
	return 0;
}
