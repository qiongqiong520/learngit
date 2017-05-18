 ///
 /// @file    51753数组初始化.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 16:10:53
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int monthDays[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int mian()
{
	int year,month,day;
	int days=0;
	cin>>year>>month>>day;
	for(int y=2012;year;++y)
	{
		if((y%4==0&&y%100!=0)||year%400==0)
			days+=366;
		else
			days+=365;
	}
	if((year%4==0 && year%100!=0) || year%400==0)
		monthDays[2]=29;
	for(int m=1;m<month;++m)
		days+=monthDays[m];
	days+=day;
	days-=22;//2012年1月22日是星期天
	cout<<days%7<<endl;
	return 0;
}

