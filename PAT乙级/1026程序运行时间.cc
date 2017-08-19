 ///
 /// @file    1026程序运行时间.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 17:34:20
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc,char* argv[])
{
	int begin,end;
	while(cin>>begin>>end)
	{
		int time=end-begin;
		float t =(float)time/100;
		time /=100;
		t -=time;
		int hour,min,sec;
		sec =time%60;time /=60;
		min =time%60;time /=60;
		hour =time;
		if(t>=0.5)sec++;
		cout<<hour/10<<hour%10<<":"<<min/10<<min%10<<":"
			<<sec/10<<sec%10<<endl;
	}
	return 0;
}

