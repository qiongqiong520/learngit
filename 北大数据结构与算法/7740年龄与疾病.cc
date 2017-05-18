 ///
 /// @file    7740年龄与疾病.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 09:06:24
 ///
 
#include <iostream>
#include<iomanip>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int age1=0,age2=0,age3=0,age4=0;
	int n;
	cin>>n;
	int total =0;
	for(int i=0;i<n;i++)
	{
	 	int age;
		cin>>age;
		//按照0-18，19-35，36-60，61以上输出病患总人数比例，一把粉笔形式输出
		//精确到小数点后两位
		if(age>=0&&age<=18)
			++age1;
		else if (age>=19&&age<=35)
			++age2;
		else if (age>=36&&age<=60)
			++age3;
		else 
			++age4;
		++total;
	}
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2);
	cout<<(double)age1/total*100<<"%"<<endl;
	cout<<(double)age2/total*100<<"%"<<endl;
	cout<<(double)age3/total*100<<"%"<<endl;
	cout<<(double)age4/total*100<<"%"<<endl;
	return 0;
}
