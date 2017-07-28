///
 /// @file    1735判断闰年.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-18 23:08:24
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
     int a;
    cin>>a;
    if(a%4==0)
	{
		if(a%100==0 && a%400!=0 || a%3200==0)
			cout<<"N"<<endl;
		else 
			 cout<<"Y"<<endl;
	
	}
	else cout<<"N"<<endl;
    return 0;
}
